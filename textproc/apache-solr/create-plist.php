<?php

if(empty($argv[1]))
  die("please specify solr-worksrc\n");

$strGitLabDir = $argv[1];

if(!is_dir($strGitLabDir))
  die("given path is not a dir: $strGitLabDir\n");

if(!is_readable($strGitLabDir))
  die("given path is not readable: $strGitLabDir\n");

// remove last slash of path if given to easy
// path handling later
if(strrpos($strGitLabDir, '/') == (strlen($strGitLabDir) - 1))
  $strGitLabDir = substr($strGitLabDir, 0, strlen($strGitLabDir) - 1);

$objDir = new RecursiveDirectoryIterator($strGitLabDir);
$objDir = new RecursiveIteratorIterator($objDir);

$arrFiles = array();

// iterate through complete given work-dir
foreach($objDir AS $objFile) {

  // skip dirs, we only want files
  if(!$objFile->isFile())
    continue;

  // skip unwanted files
  if(in_array($objFile->getExtension(),
              array('orig', 'bak', 'gitkeep', 'gitignore')))
     continue;

  // skip lock file, it shoud be generated when GitLab is started
  if('Gemfile.lock' === $objFile->getFilename())
    continue;

  // strip given dir - we just want the aim-dir
  $intEndPosOfDir = strpos($objFile->getRealPath(), $strGitLabDir) + strlen($strGitLabDir);
  $strFilePath    = substr($objFile->getRealPath(), $intEndPosOfDir);

  // list of config files to ignore
  $arrConfigFiles = array('/etc/solr.in.sh.sample',
                          '/var/db/solr/solr.xml.sample');

  // skip config files
  if(in_array($strFilePath, $arrConfigFiles))
    continue;

  $arrFiles[] = "solr$strFilePath";

}

sort($arrFiles);

// go through the files and print them
foreach($arrFiles AS $strFile) {

    print "$strFile\n";
}

// at least print static block of dirs and config files
print "@dir(solr,solr) /var/db/solr
@dir(solr,solr) /var/log/solr
@sample etc/solr.in.sh.sample
@sample(solr,solr) /var/db/solr/solr.xml.sample
%%JTS%%solr/server/solr-webapp/webapp/WEB-INF/lib/jts-core.jar
";
print "\n";


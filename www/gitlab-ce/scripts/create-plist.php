<?php

if(empty($argv[1]))
  die("please specify gitlab-worksrc\n");

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
  $arrConfigFiles = array('/config/database.yml.example',
                          '/config/gitlab.yml.example',
                          '/config/unicorn.rb.example',
                          '/config/puma.rb.example',
                          '/config/resque.yml.example',
                          '/config/secrets.yml.example',
                          '/config/initializers/rack_attack.rb.example',
			  '/config/cable.yml.example',
			  '/config/initializers/devise_password_length.rb.example',
			  '/config/redis.cache.yml.example',
			  '/config/redis.queues.yml.example',
			  '/config/redis.shared_state.yml.example',
			  '/config/sidekiq.yml.example',
                          '/lib/support/nginx/gitlab',
                          '/lib/support/nginx/gitlab-ssl',
			  '/config/secrets.yml' );

  // skip config files
  if(in_array($strFilePath, $arrConfigFiles))
    continue;

  $arrFiles[] = "%%WWWDIR%%$strFilePath";

}

sort($arrFiles);

// go through the files and print them
foreach($arrFiles AS $strFile) {

  // if a file starts with /bin/ add executable rights
  if(is_int(strpos($strFile, '%%WWWDIR%%/bin/'))) {
    print "@(git,,544) $strFile\n";

  // schema.rb needs git-owner, because its written on updates
  } elseif ($strFile === '%%WWWDIR%%/db/schema.rb') {
    print "@(git,,) $strFile\n";

  // gitlab.po(t) files needs git-owner, because there were compiled on update/installation
  } elseif (fnmatch('*/gitlab.pot', $strFile) ||
            fnmatch('*/gitlab.po', $strFile) ||
            fnmatch('*/gitlab.po.time_stamp', $strFile)) {
    print "@(git,,) $strFile\n";

    // also there is javascript compiled on update/install which is localiced
  } elseif (fnmatch('*/locale/*/app.js', $strFile) ||
            fnmatch('*/locale/index.js', $strFile)) {
    print "@(git,,) $strFile\n";
    
  // everything else is just fine
  } else {
    print "$strFile\n";
  }
}

// at least print static block of dirs and config files
print "@owner git
@group www
@dir(git,git) %%WWWDIR%%/
@dir %%WWWDIR%%/app/assets/images/auth_buttons/
@dir %%WWWDIR%%/app/assets/javascripts/locale/
@dir(git,git,554) %%WWWDIR%%/bin
@dir %%WWWDIR%%/config
@dir(,,700) %%WWWDIR%%/builds
@dir %%WWWDIR%%/changelogs/unreleased
@dir(,,744) %%WWWDIR%%/locale
@dir %%WWWDIR%%/lib/assets
@dir(,,744) %%WWWDIR%%/locale/bg
@dir(,,744) %%WWWDIR%%/locale/de
@dir(,,744) %%WWWDIR%%/locale/eo
@dir(,,744) %%WWWDIR%%/locale/es
@dir(,,744) %%WWWDIR%%/locale/fil_PH
@dir(,,744) %%WWWDIR%%/locale/fr
@dir(,,744) %%WWWDIR%%/locale/id_ID
@dir(,,744) %%WWWDIR%%/locale/it
@dir(,,744) %%WWWDIR%%/locale/ja
@dir(,,744) %%WWWDIR%%/locale/ko
@dir(,,744) %%WWWDIR%%/locale/nl_NL
@dir(,,744) %%WWWDIR%%/locale/pl_PL
@dir(,,744) %%WWWDIR%%/locale/pt_BR
@dir(,,744) %%WWWDIR%%/locale/ru
@dir(,,744) %%WWWDIR%%/locale/tr_TR
@dir(,,744) %%WWWDIR%%/locale/uk
@dir(,,744) %%WWWDIR%%/locale/zh_CN
@dir(,,744) %%WWWDIR%%/locale/zh_HK
@dir(,,744) %%WWWDIR%%/locale/zh_TW
@dir(,,744) %%WWWDIR%%/log
@dir(,,744) %%WWWDIR%%/plugins
@dir %%WWWDIR%%/public
@dir %%WWWDIR%%/public/assets
@dir(,,700) %%WWWDIR%%/public/uploads
@dir %%WWWDIR%%/qa/qa/specs/features/api/2_plan
@dir %%WWWDIR%%/qa/qa/specs/features/api/4_verify
@dir %%WWWDIR%%/qa/qa/specs/features/api/5_package
@dir %%WWWDIR%%/qa/qa/specs/features/api/6_release
@dir %%WWWDIR%%/qa/qa/specs/features/api/7_configure
@dir %%WWWDIR%%/qa/qa/specs/features/api/8_monitor
@dir %%WWWDIR%%/qa/qa/specs/features/browser_ui/5_package
@dir %%WWWDIR%%/spec/support/gitlab-git-test.git/refs/heads
@dir %%WWWDIR%%/spec/support/gitlab-git-test.git/refs/tags
@dir(,,700) %%WWWDIR%%/shared
@dir(,,700) %%WWWDIR%%/shared/artifacts
@dir(,,700) %%WWWDIR%%/shared/artifacts/tmp
@dir(,,700) %%WWWDIR%%/shared/artifacts/tmp/cache
@dir(,,700) %%WWWDIR%%/shared/artifacts/tmp/uploads
@dir(,,700) %%WWWDIR%%/shared/artifacts/tmp/work
@dir(,,770) %%WWWDIR%%/shared/pages
@dir(,,700) %%WWWDIR%%/shared/tmp
@dir(,,700) %%WWWDIR%%/shared/lfs-objects
@dir(,,700) %%WWWDIR%%/shared/registry
@dir(,,700) %%WWWDIR%%/spec/javascripts/fixtures
@dir(,,770) %%WWWDIR%%/tmp
@dir(,,770) %%WWWDIR%%/tmp/backups
@dir(,,770) %%WWWDIR%%/tmp/cache
@dir(,,770) %%WWWDIR%%/tmp/feature_flags
@dir(,,770) %%WWWDIR%%/tmp/pids
@dir(,,770) %%WWWDIR%%/tmp/prometheus_multiproc_dir
@dir(,,770) %%WWWDIR%%/tmp/prometheus_multiproc_dir/puma
@dir(,,770) %%WWWDIR%%/tmp/prometheus_multiproc_dir/sidekiq
@dir(,,770) %%WWWDIR%%/tmp/prometheus_multiproc_dir/unicorn
@dir(,,770) %%WWWDIR%%/tmp/sessions
@dir(,,770) %%WWWDIR%%/tmp/sockets
@dir(,,770) %%WWWDIR%%/tmp/sockets/private
@dir(,,770) %%WWWDIR%%/vendor
@dir(,,770) %%WWWDIR%%/vendor/assets
@dir(,,770) %%WWWDIR%%/vendor/assets/stylesheets
@dir(,,770) %%WWWDIR%%/workhorse/changelogs/unreleased
@sample %%WWWDIR%%/config/puma.rb.sample
@sample(git,www,0600) %%WWWDIR%%/config/secrets.yml.sample
@sample %%WWWDIR%%/config/redis.cache.yml.sample
@sample %%WWWDIR%%/config/sidekiq.yml.sample
@sample %%WWWDIR%%/config/cable.yml.sample
@sample %%WWWDIR%%/config/gitlab.yml.sample
@sample %%WWWDIR%%/config/redis.queues.yml.sample
@sample %%WWWDIR%%/config/initializers/devise_password_length.rb.sample
@sample %%WWWDIR%%/config/redis.shared_state.yml.sample
@sample %%WWWDIR%%/config/unicorn.rb.sample
@sample %%WWWDIR%%/config/resque.yml.sample
@sample %%WWWDIR%%/config/database.yml.sample
@sample %%WWWDIR%%/lib/support/nginx/gitlab.sample
@sample %%WWWDIR%%/lib/support/nginx/gitlab-ssl.sample";

print "\n";


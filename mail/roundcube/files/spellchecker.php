<?php
/*-
 * Copyright (c) 2006 Alex Dupre.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
$lang = $_REQUEST["lang"];
$xml = new SimpleXMLElement(file_get_contents("php://input"));
$spell = pspell_new($lang, "", "", "utf-8", PSPELL_NORMAL);
$suggestions = array();
$offset = 0;
mb_regex_encoding("UTF-8");
foreach (mb_split("\n", $xml->text) as $line) {
  $len = mb_strlen($line, "UTF-8");
  mb_ereg_search_init($line, "\w+");
  while (($wpos = mb_ereg_search_pos()) != FALSE) {
    $word = mb_substr($line, $wpos[0], $wpos[1]);
    if (!pspell_check($spell, $word)) {
      $woffset = mb_strlen(mb_substr($line, 0, $wpos[0]), "UTF-8");
      $wlen = mb_strlen($word, "UTF-8");
      array_push($suggestions, array($offset + $woffset, $wlen, pspell_suggest($spell, $word)));
    }
  }
  $offset += $len + 1;
}
$xml = new SimpleXMLElement("<spellresponse/>");
$xml->addAttribute("error", count($suggestions) ? "1" : "0");
foreach ($suggestions as $s) {
  $c = $xml->addChild("c", join("\t", $s[2]));
  $c->addAttribute("o", $s[0]);
  $c->addAttribute("l", $s[1]);
  $c->addAttribute("s", "1");
}
header('Content-Type: text/xml');
echo $xml->asXML();

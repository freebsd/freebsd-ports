#!/bin/sh
#
# wrapper for momspider
#
# MOMspider is a web-roaming robot that specializes in the maintenance
# of distributed hypertext infostructures (i.e. wide-area webs). The
# program is written in Perl and, once customized for your site, should
# work on any UNIX-based system with Perl 4.036.            
#
# The momspider documentation is in /usr/local/momspider/README.html
#
# $FreeBSD$

PATH=/bin:/usr/bin; export PATH
momhome=/usr/local/momspider

: ${LIBWWW_PERL=$momhome/libwww-perl-0.40}; export LIBWWW_PERL
: ${MOMSPIDER_HOME=$momhome}; export MOMSPIDER_HOME

exec perl ${MOMSPIDER_HOME}/momspider "$@"

# Ports collection makefile for:  pear-Net_LDAP
# Date created:			  26 June 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	Net_LDAP
DISTVERSION=	1.1.4
CATEGORIES=	net pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	OO interface for searching and manipulating LDAP-entries

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	ldap
CATEGORY=	Net
FILES=		LDAP.php LDAP/LDIF.php \
		LDAP/Entry.php LDAP/Filter.php LDAP/RootDSE.php \
		LDAP/Schema.php LDAP/Search.php LDAP/Util.php
DOCS=		README.txt RootDSE.txt Schema.txt utf8.txt manual.html
_DOCSDIR=	doc
TESTS=		AllTests.php Net_LDAPTest.php \
		Net_LDAP_EntryTest.php Net_LDAP_FilterTest.php \
		Net_LDAP_RootDSETest.php Net_LDAP_SearchTest.php \
		Net_LDAP_UtilTest.php Net_LDAP_LDIFTest.php \
		ldapconfig.ini.dist ldapldifconfig.ini.dist \
		ldif_data/changes.ldif ldif_data/malformed_encoding.ldif \
		ldif_data/malformed_syntax.ldif ldif_data/malformed_wrapping.ldif \
		ldif_data/sorted_w40.ldif ldif_data/sorted_w50.ldif \
		ldif_data/unsorted_w30.ldif ldif_data/unsorted_w50.ldif
EXAMPLES=	add_entry.php connecting.php fetch_entry.php \
		modify_entry.php modify_entry2.php search_entries.php
_EXAMPLESDIR=	doc/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>

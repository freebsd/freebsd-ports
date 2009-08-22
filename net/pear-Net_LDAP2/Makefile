# Ports collection makefile for:  pear-Net_LDAP2
# Date created:			  04 May 2004
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net_LDAP2
PORTVERSION=	2.0.6
PORTEPOCH=	1
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	OO interface for searching and manipulating LDAP-entries

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	ldap
CATEGORY=	Net
FILES=		LDAP2.php LDAP2/LDIF.php \
		LDAP2/Entry.php LDAP2/Filter.php LDAP2/RootDSE.php \
		LDAP2/Schema.php LDAP2/Search.php LDAP2/Util.php \
		LDAP2/SchemaCache.interface.php \
		LDAP2/SimpleFileSchemaCache.php
DOCS=		README.txt RootDSE.txt Schema.txt utf8.txt manual.html
_DOCSDIR=	doc
TESTS=		AllTests.php Net_LDAP2Test.php \
		Net_LDAP2_EntryTest.php Net_LDAP2_FilterTest.php \
		Net_LDAP2_RootDSETest.php Net_LDAP2_SearchTest.php \
		Net_LDAP2_UtilTest.php Net_LDAP2_LDIFTest.php \
		ldapconfig.ini.dist ldapldifconfig.ini.dist \
		ldif_data/changes.ldif ldif_data/malformed_encoding.ldif \
		ldif_data/malformed_syntax.ldif ldif_data/malformed_wrapping.ldif \
		ldif_data/sorted_w40.ldif ldif_data/sorted_w50.ldif \
		ldif_data/unsorted_w30.ldif ldif_data/unsorted_w50.ldif \
		ldif_data/unsorted_w50_WIN.ldif
EXAMPLES=	add_entry.php connecting.php fetch_entry.php \
		modify_entry.php modify_entry2.php search_entries.php \
		schema_cache.php
_EXAMPLESDIR=	doc/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>

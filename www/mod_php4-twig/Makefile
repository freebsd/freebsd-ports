# New ports collection makefile for:	mod_pgp4-twig
# Date created:		09.Oct 2003
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

CATEGORIES=	www
PKGNAMESUFFIX=	-twig

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../../lang/php4

BATCH=		yes
PKGMESSAGE=	${PORTSDIR}/www/mod_php4/pkg-message
WITHOUT_CLI=	yes
WITHOUT_X11=	yes
PHP4_OPTIONS=	CTYPE IMAP OPENSSL POSTGRESQL PCRE POSIX SESSION TOKENIZER XML ZLIB

WITHOUT_MYSQL=		yes

WITH_CTYPE=		yes
WITH_IMAP=		yes
WITH_OPENSSL=		yes
WITH_POSTGRESQL=	yes
WITH_PCRE=		yes
WITH_POSIX=		yes
WITH_SESSION=		yes
WITH_TOKENIZER=		yes
WITH_XML=		yes
WITH_ZLIB=		yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"

# New ports collection makefile for:	sympa-elixus
# Date created:        29 November 2003
# Whom:                Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTVERSION=	20041024
MASTER_SITES=	http://p4.elixus.org/hist/
PKGNAMESUFFIX=	-elixus

COMMENT=	An electronic mailing list manager with elixus.org patches

BUILD_DEPENDS=	${SITE_PERL}/Locale/Maketext/Lexicon.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

IGNORE=	is no longer maintained, no longer fetchable, no longer builds with sympa
DEPRECATED=	no longer maintained, no longer fetchable, no longer builds with sympa
EXPIRATION_DATE=	2010-09-25

MASTERDIR=	${.CURDIR}/../../mail/sympa
MD5_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"

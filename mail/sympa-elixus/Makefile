# New ports collection makefile for:	sympa-elixus
# Date created:        29 November 2003
# Whom:                Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTVERSION=	9388
PORTREVISION=	0
MASTER_SITES=	http://p4.elixus.org/hist/
PKGNAMESUFFIX=	-elixus
DISTNAME=	sympa-${PORTVERSION}

COMMENT=	An electronic mailing list manager with elixus.org patches

BUILD_DEPENDS+=	${SITE_PERL}/Locale/Maketext/Lexicon.pm:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit

MASTERDIR=	${.CURDIR}/../../mail/sympa
MD5_FILE=	${.CURDIR}/distinfo
PATCHDIR=	${.CURDIR}/files
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
PKGINSTALL=	${MASTERDIR}/pkg-install
PKGDEINSTALL=	${MASTERDIR}/pkg-deinstall
WRKSRC=		${WRKDIR}/sympa

.include "${MASTERDIR}/Makefile"

# New ports collection makefile for:	hardlink
# Date created:				14 January 2011
# Whom:					Douglas Thrift
#
# $FreeBSD$
#

PORTNAME=	hardlink
PORTVERSION=	0.2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://jak-linux.org/projects/hardlink/ \
		DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	douglas@douglasthrift.net
COMMENT=	Replace file copies using hardlinks

LICENSE=	MIT

USE_PKGCONFIG=	yes

MAN1=		hardlink.1
PLIST_FILES=	bin/hardlink
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

OPTIONS_DEFINE=	PCRE

OPTIONS_DEFAULT=PCRE

PORTSCOUT=	limit:(?<!~rc[0-9])$$

.include <bsd.port.options.mk>

.if defined(WITHOUT_PCRE)
MAKE_ENV+=	ENABLE=
.else
LIB_DEPENDS+=	pcreposix:${PORTSDIR}/devel/pcre
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hardlink ${PREFIX}/bin/hardlink
	${INSTALL_MAN} ${WRKSRC}/hardlink.1 ${MAN1PREFIX}/man/man1/hardlink.1

.include <bsd.port.mk>

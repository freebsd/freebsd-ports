# ex:ts=8
# Ports collection makefile for:	retawq
# Date created:			Dec 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	retawq
PORTVERSION=	0.1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
MAKE_ENV=	THREAD_CFLAGS="${PTHREAD_CFLAGS}" THREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	build_binary

MAN1=		retawq.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/retawq ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docu/retawq.1 ${MANPREFIX}/man/man1
.for lang in de es fr
	${INSTALL_DATA} ${WRKSRC}/i18n/${lang}.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docu/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>

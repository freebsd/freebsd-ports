# New ports collection makefile for:	mailsync
# Date created:		03 Feb 2003
# Whom:			Maxim Tulyuk <mt@primats.org.ua>
#
# $FreeBSD$
#

PORTNAME=	mailsync
PORTVERSION=	4.4.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	mt@primats.org.ua
COMMENT=	Mailsync is a way of keeping a collection of mailboxes synchronized

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GCC=	2.95

ALL_TARGET=	default

MAN1=		mailsync.1

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/examples/mailsync \
		${WRKSRC}/mailsync.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mailsync ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mailsync.1  ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README   ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/mailsync ${EXAMPLESDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	xlhtml
# Date created:				27 March 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xlhtml
PORTVERSION=	0.5.1
CATEGORIES=	textproc
MASTER_SITES=	http://chicago.sourceforge.net/xlhtml/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sobomax@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

MAN1=		ppthtml.1 xlhtml.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xlhtml
	${INSTALL_MAN} ${WRKSRC}/xlhtml/README \
		${PREFIX}/share/doc/xlhtml/README.xlhtml
	${INSTALL_MAN} ${WRKSRC}/ppthtml/README \
		${PREFIX}/share/doc/xlhtml/README.ppthtml
.endif

.include <bsd.port.mk>

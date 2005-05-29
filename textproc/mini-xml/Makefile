# New ports collection makefile for:	mini-xml
# Date created:				01 Jan 2004
# Whom:					Vladimir Osintsev <oc@cynic.ru>
# $FreeBSD$

PORTNAME=	mini-xml
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.easysw.com/pub/mxml/${PORTVERSION}/ \
		http://www.nu6.org/_/mirror/ftp.easysw.com/pub/mxml/${PORTVERSION}/
DISTNAME=	mxml-${PORTVERSION}

MAINTAINER=	oc@cynic.ru
COMMENT=	Lightweight XML parsing library

USE_GNOME=	gnometarget pkgconfig
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}

MAN1=		mxmldoc.1
MAN3=		mxml.3
CAT1=		mxmldoc.1
CAT3=		mxml.3

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/test.xml ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/samples
.for SN in class enum function struct
	${INSTALL_MAN} ${WRKSRC}/test/${SN}.cxx ${DOCSDIR}/samples/
.endfor
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	mini-xml
# Date created:				01 Jan 2004
# Whom:					Vladimir Osintsev <oc@nm.ru>
# $FreeBSD$

PORTNAME=	mini-xml
PORTVERSION=	2.0.r1
CATEGORIES=	textproc
MASTER_SITES=	http://www.easysw.com/~mike/mxml/swfiles/
DISTNAME=	mxml-${PORTVERSION:S/.r/rc/}

MAINTAINER=	oc@nm.ru
COMMENT=	Lightweight XML parsing library

USE_GNOME=	pkgconfig
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PORTNAME}

MAN1=		mxmldoc.1
MAN3=		mxml.3
CAT1=		mxmldoc.1
CAT3=		mxml.3

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

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

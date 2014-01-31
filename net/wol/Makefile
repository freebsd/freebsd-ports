# Created by: ijliao
# $FreeBSD$

PORTNAME=	wol
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/ahh/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to wake up Wake-On-LAN compliant computers

USES=		perl5
GNU_CONFIGURE=	yes
USE_PERL5=	build
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		wol
DOCS=		AUTHORS NEWS README TODO

OPTIONS_DEFINE=	DOCS NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext iconv
NLS_CONFIGURE_OFF=	--disable-nls

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

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
GNU_CONFIGURE=		yes
USE_PERL5=	build
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

MAN1=		wol.1
INFO=		wol
DOCS=		AUTHORS NEWS README TODO

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

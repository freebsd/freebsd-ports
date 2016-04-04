# Created by: at@rominet.net
# $FreeBSD$

PORTNAME=	ssltunnel
PORTVERSION=	1.18
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.hsc.fr/ressources/outils/ssltunnel/download/
PKGNAMESUFFIX=	-client

MAINTAINER=	crees@FreeBSD.org
COMMENT=	PPP over SSL virtual private networking (client part)

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	GUI DOCS
GUI_DESC=	GTK 1.2 graphical interface

CONFIGURE_ARGS=	--disable-server --with-iconv=${ICONV_PREFIX}
GNU_CONFIGURE=	yes
USES=		iconv
USE_OPENSSL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
USE_GNOME=	gtk12
USES+=		perl5
RUN_DEPENDS=	p5-Gtk>=0:x11-toolkits/p5-Gtk
MAN1+=		gpppclient.1
PLIST_SUB+=	PERLGTK=""
.else
PLIST_SUB+=	PERLGTK="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|with_iconv|with-iconv|g' ${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/LISEZ-MOI \
		${STAGEDIR}${DOCSDIR}/client.LISEZ-MOI
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/client.README
	${MKDIR} ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${WRKSRC}/client/tunnel.conf \
		${STAGEDIR}${ETCDIR}/client.conf.sample

.include <bsd.port.mk>

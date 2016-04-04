# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	gcombust
PORTVERSION=	0.1.55
PORTREVISION=	8
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.symnds.com/software/misc/ \
		http://www.egr.msu.edu/~mcdouga9/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ frontend for mkisofs and cdrecord

LICENSE=	GPLv2

RUN_DEPENDS=	cdlabelgen:print/cdlabelgen \
		cdrecord:sysutils/cdrtools

USES=		gettext perl5
USE_PERL5=	build
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-included-gettext --datadir=${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
	    ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|==|=|g' ${WRKSRC}/po/Makefile.in.in

post-configure:
	cd ${WRKSRC}/po && ${MAKE} update-po

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

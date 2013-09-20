# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	gcombust
PORTVERSION=	0.1.55
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.symnds.com/software/misc/ \
		http://www.egr.msu.edu/~mcdouga9/

MAINTAINER=	mcdouga9@msu.edu
COMMENT=	A GTK+ frontend for mkisofs and cdrecord

LICENSE=	GPLv2

RUN_DEPENDS=	cdlabelgen:${PORTSDIR}/print/cdlabelgen \
		cdrecord:${PORTSDIR}/sysutils/cdrtools

USES=		gettext perl5
USE_PERL5=	build
USE_GNOME=	gtk12 gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-included-gettext --datadir=${PREFIX}/share
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
.include <bsd.port.options.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|g' \
	    ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|==|=|g' ${WRKSRC}/po/Makefile.in.in

post-configure:
	cd ${WRKSRC}/po && ${MAKE} update-po

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	gcombust
# Date created:		Tue Jun 22 21:17:03 MET DST 1999
# Whom:			Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	gcombust
PORTVERSION=	0.1.55
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror.symnds.com/software/misc/ \
		http://www.egr.msu.edu/~mcdouga9/

MAINTAINER=	mcdouga9@msu.edu
COMMENT=	A GTK+ frontend for mkisofs and cdrecord

LICENSE=	GPLv2

RUN_DEPENDS=	cdlabelgen:${PORTSDIR}/print/cdlabelgen

USE_GETTEXT=	yes
USE_PERL5_BUILD=yes
USE_GNOME=	gtk12 gnomehier
USE_CDRTOOLS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-included-gettext --datadir=${PREFIX}/share
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|==|=|g' ${WRKSRC}/po/Makefile.in.in

post-configure:
	cd ${WRKSRC}/po && ${MAKE} update-po

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gcombust
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/NEWS ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:    k3b
# Date created:                         2003/02/13
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	k3b
PORTVERSION=	0.10.3
PORTREVISION=	1
CATEGORIES=	sysutils multimedia kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	A CD/DVD recording GUI for KDE

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		cdrdao:${PORTSDIR}/sysutils/cdrdao \
		mkisofs:${PORTSDIR}/sysutils/mkisofs
LIB_DEPENDS=	mad:${PORTSDIR}/audio/libmad \
		ogg:$(PORTSDIR)/audio/libogg

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-k3bsetup=no
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_KDELIBS_VER=	3
USE_REINPLACE=	yes

pre-configure:
	${REINPLACE_CMD} "s,-pedantic ,,g; \
			  s,-pthread,${PTHREAD_LIBS},g; \
			  s,-O2 ,,g" ${WRKSRC}/configure
.for i in config.h.in Makefile.in
	${TOUCH} ${WRKSRC}/${i}
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}
	@sleep 5

showinfo:
	more ${PKGMESSAGE}

.include <bsd.port.mk>

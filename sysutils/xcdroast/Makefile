# New ports collection makefile for:	xcdroast
# Date Created:		28 Sep 2000
# Whom:			Oliver Lehmann <Kai_Allard_Liao@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	xcdroast
PORTVERSION=	0.98.a.10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xcdroast.org/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a./alpha/}

MAINTAINER=	lehmann@ans-netz.de

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib gdkpixbuf

MAKE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		IMLIB_CONFIG="${IMLIB_CONFIG}"

MAN1=		xcdroast.1

post-patch:
	for i in xcdroast.h Makefile ; do \
	  ${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/$$i ; \
	done

	for i in Makefile xcdroast.h ; do \
	  ${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/$$i ; \
	done

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

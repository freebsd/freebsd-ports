# New ports collection makefile for:   synce-librapi2
# Date created:                14 June 2003
# Whom:                        Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$

PORTNAME=	synce-librapi2
PORTVERSION=	0.9.1
CATEGORIES=	palm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities/libraries to make RAPI calls on WinCE devices

LIB_DEPENDS+=	synce.0:${PORTSDIR}/palm/synce-libsynce

ONLY_FOR_ARCHS=	i386 amd64

MAN1=		pcp.1 pls.1 pmkdir.1 pmv.1 prm.1 prmdir.1 prun.1 pstatus.1 rapiconfig.1 synce-install-cab.1 synce-remove-program.1 synce-list-programs.1

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-libiconv=${LOCALBASE}
CONFIGURE_ARGS+=	--with-libsynce=${LOCALBASE}

INSTALLS_SHLIB=	yes

post-patch:
.for f in synce-install-cab.in synce-remove-program.in
	@${REINPLACE_CMD} -e 's+bin/bash+bin/sh+' ${WRKSRC}/script/${f}
.endfor

.include <bsd.port.mk>

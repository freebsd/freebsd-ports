# Ports collection makefile for:  xprobe
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xprobe2
PORTVERSION=	0.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xprobe

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	ICMP active OS fingerprint scanner

HAS_CONFIGURE=	yes

MAN1=		xprobe2.1

pre-configure:
	( cd ${WRKSRC}/libs-external/USI++/src ; CFLAGS="${CFLAGS}" ./configure --prefix=${PREFIX} ${CONFIGURE_TARGET} )

# force -O0 for these modules otherwise gcc 3.3.3 20031106 dies with internal error
post-configure:
	@${FIND} ${WRKSRC}/src/xpmodules/os_probe -name Makefile | ${XARGS} ${REINPLACE_CMD} -e 's|${CFLAGS}|-O0|'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xprobe2 ${PREFIX}/bin
	${INSTALL} -d ${PREFIX}/etc/xprobe2
	${INSTALL_DATA} ${WRKSRC}/etc/xprobe2.conf ${PREFIX}/etc/xprobe2
	${INSTALL_MAN} ${WRKSRC}/docs/xprobe2.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

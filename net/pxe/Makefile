# New ports collection makefile for:	pxe
# Date created:        			7 April 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pxe
PORTVERSION=	1.4.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.kano.org.uk/projects/pxe/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	PXE daemon, set up a boot menu for netbooting PXE enabled clients

USE_RC_SUBR=	pxe
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-config=${PREFIX}/etc/pxe.conf \
			--with-log=/var/log/pxe.log \
			--with-setuid=nobody

DOCS=	Changes INSTALL LICENCE README THANKS

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|/tmp/pxe.pid|/var/run/pxe.pid|' ${WRKSRC}/autoconf.h.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pxe ${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/pxe.conf ${PREFIX}/etc/pxe.conf.sample
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

# New ports collection makefile for:	pks
# Date created:		15 Jan 2001
# Whom:			kris@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	pks
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	${PATCH_SITES} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	http://www.mit.edu/people/marc/pks/
PATCHFILES=	pks094-patch2 \
		x509patch
PATCH_DIST_STRIP=-p1

MAINTAINER=	jharris@widomaker.com
COMMENT=	PGP Public Key Server

LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --datadir=${PREFIX}/share/pks --localstatedir=/var/pks \
		--sysconfdir=${PREFIX}/share/examples \
		--libdir=${LOCALBASE}/lib
MAKE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib

MAN5=	pksd.conf.5
MAN8=	pks-intro.8 pksclient.8 pksd.8 pksdctl.8

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/pksd.sh > ${WRKDIR}/pksd.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pksd.sh ${PREFIX}/etc/rc.d/pksd.sh
.if !exists(${PREFIX}/etc/pksd.conf)
	${INSTALL_DATA} ${WRKSRC}/pksd.conf ${PREFIX}/etc/pksd.conf
.endif
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

# New ports collection makefile for:	pkgfe
# Date created:				2006-01-14
# Whom:					Sulev-Madis Silber <madis555@hot.ee>
#
# $FreeBSD$
#

PORTNAME=	pkgfe
PORTVERSION=	20070411
CATEGORIES=	ports-mgmt
MASTER_SITES=	http://kodu.neti.ee/~madis555/pkgfe/releases/ \
		http://ketas.si.pri.ee/pkgfe/releases/ \
		http://helpfreebsd.net/pkgfe/releases/ \
		http://ketas.life.ee/pkgfe/releases/

MAINTAINER=	madis555@hot.ee
COMMENT=	Ncurses frontend for ports collection

RUN_DEPENDS=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade \
		portaudit:${PORTSDIR}/ports-mgmt/portaudit

MAN8=		pkgfe.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600033 && ( ${OSVERSION} < 504103 || ${OSVERSION} > 600000 )
RUN_DEPENDS+=	portsnap:${PORTSDIR}/ports-mgmt/portsnap
.endif

NO_BUILD=	yes

do-install:
	${REINPLACE_CMD} -e 's|%PREFIX%|${PREFIX}|g' ${WRKSRC}/pkgfe
	${INSTALL_SCRIPT} ${WRKSRC}/pkgfe ${PREFIX}/sbin/pkgfe
	${INSTALL_DATA} ${WRKSRC}/pkgfe.conf ${PREFIX}/etc/pkgfe.conf.sample
	${INSTALL_MAN} ${WRKSRC}/pkgfe.8 ${PREFIX}/man/man8

post-install:
	@if [ ! -f ${PREFIX}/etc/pkgfe.conf ]; then \
		${CP} -p ${PREFIX}/etc/pkgfe.conf.sample ${PREFIX}/etc/pkgfe.conf ; \
	fi

.include <bsd.port.post.mk>

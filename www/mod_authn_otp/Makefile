# Created by: Alexander Hausner <alex@hugo.bmg.gv.at>
# $FreeBSD$

PORTNAME=	mod_authn_otp
PORTVERSION=	1.1.5
CATEGORIES=	www
MASTER_SITES=	http://mod-authn-otp.googlecode.com/files/ \
		http://alex.bmg.gv.at/programs/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Apache module for one-time password authentication


GNU_CONFIGURE=	yes
USE_APACHE=	22

MAN1=		otptool.1

PORTEXAMPLES=	users.sample

.include <bsd.port.options.mk>

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man

post-configure:
	@${REINPLACE_CMD} 's|CFLAGS =|CFLAGS ?=|' \
		${WRKSRC}/Makefile

post-install:
	@${APXS} -e -A -n ${PORTNAME:S/mod_//} ${APACHEMODDIR}/${PORTNAME}.so
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/users.sample ${EXAMPLESDIR}/
.endif

.include <bsd.port.mk>

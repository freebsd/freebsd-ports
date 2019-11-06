# Created by: dikshie@lapi.itb.ac.id
# $FreeBSD$

PORTNAME=	ssmping
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.venaas.no/multicast/ssmping/

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	Ping for ASM and SSM

BROKEN=		unfetchable

PLIST_FILES=	bin/ssmping bin/asmping bin/mcfirst sbin/ssmpingd \
		man/man1/asmping.1.gz man/man1/mcfirst.1.gz \
		man/man1/ssmping.1.gz

do-install:
.for f in ssmping asmping mcfirst
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/ssmpingd ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>

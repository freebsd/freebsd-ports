# New ports collection makefile for: clockspeed
# Date created:		16 June 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	clockspeed
PORTVERSION=	0.62
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/clockspeed/ \
		ftp://mirror.pipex.net/pub/qmail/ \
		ftp://ftp.rifkin.technion.ac.il/pub/qmail/

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	tai.1:${PORTSDIR}/devel/libtai

ALL_TARGET=	it
INSTALL_TARGET=	setup check

MAN1=		clockadd.1 clockspeed.1 clockview.1 sntpclock.1 \
		taiclock.1 taiclockd.1

do-configure:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/INSTALL
	@${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO} ${CC} -s -L${LOCALBASE}/lib > ${WRKSRC}/conf-ld
	@${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/clockspeed
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/clockspeed
.endif
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/etc/clockspeed

.include <bsd.port.mk>

# New ports collection makefile for:	lmon
# Date created:				15 Mar 2005
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lmon
PORTVERSION=	1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bsdconsulting.no/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Near-realtime log monitoring tool, sends alerts on hits and misses

RUN_DEPENDS=	p5-Config-IniFiles>=0:${PORTSDIR}/devel/p5-Config-IniFiles \
		p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail \
		p5-File-Tail>=0:${PORTSDIR}/devel/p5-File-Tail

NO_BUILD=	yes
USES=		perl5

do-install:
	${INSTALL} -d -m 0755 ${PREFIX}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/lmon.pl ${PREFIX}/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKSRC}/control.pl ${PREFIX}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/examples/control.cfg ${PREFIX}/${PORTNAME}/control.cfg.sample
	@${REINPLACE_CMD} -E -e "s@^(user=).*@\1\"root\"@;s@^(lmonhome=).*@\1\"${PREFIX}/${PORTNAME}\"@" ${WRKSRC}/examples/lmon.init
	${INSTALL_SCRIPT} ${WRKSRC}/examples/lmon.init ${PREFIX}/etc/rc.d/lmon.sh.sample
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 0755 ${DOCSDIR}
.for f in LICENSE README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif
	${INSTALL} -d -m 0755 ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.rules ${EXAMPLESDIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

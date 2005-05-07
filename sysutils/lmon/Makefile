# New ports collection makefile for:	lmon
# Date created:				15 Mar 2005
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lmon
PORTVERSION=	1.1a
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bsdconsulting.no/tools/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Near-realtime log monitoring tool, sends alerts on hits and misses

RUN_DEPENDS=	${SITE_PERL}/Config/IniFiles.pm:${PORTSDIR}/devel/p5-Config-IniFiles \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/File/Tail.pm:${PORTSDIR}/devel/p5-File-Tail

BROKEN=		Incomplete pkg-plist

NO_BUILD=	yes
USE_REINPLACE=	yes

do-install:
	${INSTALL} -d -m 0755 ${PREFIX}/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/lmon.pl ${PREFIX}/${PORTNAME}/
	${INSTALL_SCRIPT} ${WRKSRC}/control.pl ${PREFIX}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/examples/control.cfg ${PREFIX}/${PORTNAME}/control.cfg.sample
	${INSTALL_SCRIPT} ${WRKSRC}/examples/lmon.init ${PREFIX}/etc/rc.d/lmon.sh.sample
	@${REINPLACE_CMD} -E -e "s@^(user=).*@\1\"root\"@;s@^(lmonhome=).*@\1\"${PREFIX}/${PORTNAME}\"@" ${PREFIX}/etc/rc.d/lmon.sh.sample
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

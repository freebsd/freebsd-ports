# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pwhois
PORTVERSION=	2.2.0.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://pwhois.org/get/ \
		http://mirrors.rit.edu/zi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Whois-compatible framework for disclosing routing data

RUN_DEPENDS=	p5-DBI>0:databases/p5-DBI \
		p5-Time-Format>0:devel/p5-Time-Format \
		p5-Log-Dispatch>0:devel/p5-Log-Dispatch \
		p5-Net-DNS>0:dns/p5-Net-DNS \
		p5-Net-Telnet>0:net/p5-Net-Telnet \
		p5-Net-CIDR>0:net-mgmt/p5-Net-CIDR \
		p5-RPSL-Parser>0:devel/p5-RPSL-Parser \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql

FETCH_ARGS=	-p

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

USES=		shebangfix tar:tgz
SHEBANG_FILES=	pwhois-updatedb
USE_MYSQL=	client
USE_RC_SUBR=	${PORTNAME}d
SUB_FILES=	pkg-message 512.pwhois-updatedb
SUB_LIST=	TOUCH="${TOUCH}" RM="${RM}" CHOWN="${CHOWN}" \
		USER="${USERS}" GROUP="${GROUPS}" INSTALL="${INSTALL}"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|CC = gcc |CC = ${CC}|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/etc/pwhois/|${ETCDIR}/|g' \
		-e 's|/var/pwhois/|/var/db/pwhois/|g' \
		-e 's|/var/log/|/var/log/pwhois/|g' \
		-e 's|/var/db/log/|/var/log/pwhois/|g' \
		${WRKSRC}/main.c ${WRKSRC}/pwhois-updatedb \
		${WRKSRC}/pwhois_pwdump.c ${WRKSRC}/pwhoisd.conf

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${ETCDIR} \
		${STAGEDIR}${PREFIX}/etc/periodic/daily
	@${INSTALL_SCRIPT} ${WRKDIR}/512.pwhois-updatedb \
		${STAGEDIR}${PREFIX}/etc/periodic/daily/
	@${INSTALL_PROGRAM} ${WRKSRC}/pwhoisd ${STAGEDIR}${PREFIX}/sbin/
	@${INSTALL_PROGRAM} ${WRKSRC}/pwhois-pwdump ${STAGEDIR}${PREFIX}/bin/
	@${INSTALL_SCRIPT} ${WRKSRC}/pwhois-updatedb ${STAGEDIR}${PREFIX}/sbin/
	@${INSTALL_DATA} ${WRKSRC}/pwhoisd.conf \
		${STAGEDIR}${ETCDIR}/pwhoisd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/mysql/createdb.sql ${STAGEDIR}${DATADIR}/

post-install:
	@${INSTALL} -d -o 512 -g 512 ${STAGEDIR}/var/db/pwhois
	@${INSTALL} -d -o 512 -g 512 ${STAGEDIR}/var/log/pwhois

.include <bsd.port.mk>

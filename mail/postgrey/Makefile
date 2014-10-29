# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgrey
PORTVERSION=	1.34
PORTREVISION=	8
CATEGORIES=	mail
MASTER_SITES=	http://postgrey.schweikert.ch/pub/ \
		http://postgrey.schweikert.ch/pub/old/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	Greylisting policy server for Postfix

RUN_DEPENDS=	p5-Net-Server>=0:${PORTSDIR}/net/p5-Net-Server \
		p5-IO-Multiplex>=0:${PORTSDIR}/devel/p5-IO-Multiplex \
		p5-Parse-Syslog>=0:${PORTSDIR}/textproc/p5-Parse-Syslog \
		p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS

USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}
NO_BUILD=	yes
POD2MAN?=	pod2man
PORTDOCS=	README Changes README.exim
SUB_FILES=	pkg-install
PLIST_SUB=	USER=${PGY_USERNAME} \
		GROUP=${PGY_GROUPNAME}
SUB_LIST=	USER=${PGY_USERNAME} \
		GROUP=${PGY_GROUPNAME} \
		ETCFILES="${ETCFILES}" \
		POSTGREYDIR=${PGY_DIR}
ETCFILES=	whitelist_clients whitelist_recipients
PGY_USERNAME?=	postgrey
PGY_GROUPNAME?=	postgrey
PGY_DIR?=	/var/db/postgrey

USERS=		${PGY_USERNAME}
GROUPS=		${PGY_GROUPNAME}
MPAGES=		postgrey.1 policy-test.1 postgreyreport.1

USES=		shebangfix perl5
SHEBANG_FILES=	postgrey policy-test contrib/postgreyreport

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#nogroup#${PGY_GROUPNAME}#' \
		-e 's#/etc/main.cf#/etc/postfix/main.cf#' ${WRKSRC}/postgrey
	@${REINPLACE_CMD} -e 's#/etc/postfix#${PREFIX}&#' \
		${WRKSRC}/postgrey ${WRKSRC}/postgrey_whitelist_*
	@${REINPLACE_CMD} -e 's#/var/spool/postfix/postgrey#${PGY_DIR}#' \
		${WRKSRC}/postgrey ${WRKSRC}/contrib/postgreyreport

do-install:
	${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	${POD2MAN} ${WRKSRC}/policy-test ${WRKSRC}/policy-test.1
	${POD2MAN} ${WRKSRC}/contrib/postgreyreport ${WRKSRC}/postgreyreport.1
	${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/policy-test ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/postgreyreport \
		${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/postfix ${STAGEDIR}/${PGY_DIR}
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/postgrey_${i} \
		${STAGEDIR}${PREFIX}/etc/postfix/dist-postgrey_${i}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
	@cd ${WRKSRC} && \
		${INSTALL_MAN} ${MPAGES} ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

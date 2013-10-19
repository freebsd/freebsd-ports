# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgrey
PORTVERSION=	1.34
PORTREVISION=	7
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
MAN1=		${PORTNAME}.1 policy-test.1 postgreyreport.1

USES=		shebangfix perl5
SHEBANG_FILES=	${WRKSRC}/postgrey

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's#nogroup#${PGY_GROUPNAME}#' ${WRKSRC}/postgrey
	@${REINPLACE_CMD} -e 's#/etc/main.cf#/etc/postfix/main.cf#' ${WRKSRC}/postgrey
	@${REINPLACE_CMD} -e 's#/etc/postfix#${PREFIX}&#' ${WRKSRC}/postgrey ${WRKSRC}/postgrey_whitelist_*
	@${REINPLACE_CMD} -e 's#/var/spool/postfix/postgrey#${PGY_DIR}#' ${WRKSRC}/postgrey ${WRKSRC}/contrib/postgreyreport

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	@${POD2MAN} ${WRKSRC}/policy-test ${WRKSRC}/policy-test.1
	@${POD2MAN} ${WRKSRC}/contrib/postgreyreport ${WRKSRC}/postgreyreport.1
	@${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/policy-test ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/postgreyreport ${PREFIX}/sbin
	@${INSTALL} -d ${PREFIX}/etc/postfix
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/postgrey_${i} ${PREFIX}/etc/postfix/dist-postgrey_${i}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

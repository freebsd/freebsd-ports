# Created by: Will Andrews <will@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postgrey
PORTVERSION=	1.37
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://postgrey.schweikert.ch/pub/ \
		http://postgrey.schweikert.ch/pub/old/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	Greylisting policy server for Postfix

LICENSE=	GPLv2

RUN_DEPENDS=	p5-BerkeleyDB>=0:databases/p5-BerkeleyDB \
		p5-IO-Multiplex>=0:devel/p5-IO-Multiplex \
		p5-Parse-Syslog>=0:textproc/p5-Parse-Syslog \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-Server>=0:net/p5-Net-Server \
		p5-NetAddr-IP>=0:net-mgmt/p5-NetAddr-IP

USES=		perl5 shebangfix
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

POD2MAN?=	pod2man
PORTDOCS=	README Changes README.exim

PG_DBDIR?=	/var/db/postgrey
PG_GROUP?=	postgrey
PG_RUNDIR?=	/var/run/postgrey
PG_USER?=	postgrey

SUB_LIST=	PG_DBDIR=${PG_DBDIR} \
		PG_RUNDIR=${PG_RUNDIR}

PLIST_SUB+=	PG_DBDIR=${PG_DBDIR} \
		PG_GROUP=${PG_GROUP} \
		PG_RUNDIR=${PG_RUNDIR} \
		PG_USER=${PG_USER}

USERS=		${PG_USER}
GROUPS=		${PG_GROUP}

MANPAGES=	postgrey.1 policy-test.1 postgreyreport.1
ETCFILES=	whitelist_clients whitelist_recipients

SHEBANG_FILES=	postgrey policy-test contrib/postgreyreport

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's#nogroup#${PG_GROUP}#' \
		-e 's#/etc/main.cf#/etc/postfix/main.cf#' ${WRKSRC}/postgrey
	@${REINPLACE_CMD} -e 's#/etc/postfix#${PREFIX}&#' \
		${WRKSRC}/postgrey ${WRKSRC}/postgrey_whitelist_*
	@${REINPLACE_CMD} -e 's#/var/spool/postfix/postgrey#${PG_DBDIR}#' \
		${WRKSRC}/postgrey ${WRKSRC}/contrib/postgreyreport

do-install:
	${POD2MAN} ${WRKSRC}/postgrey ${WRKSRC}/postgrey.1
	${POD2MAN} ${WRKSRC}/policy-test ${WRKSRC}/policy-test.1
	${POD2MAN} ${WRKSRC}/contrib/postgreyreport ${WRKSRC}/postgreyreport.1
	${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/policy-test ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/postgreyreport \
		${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/postfix ${STAGEDIR}${PG_DBDIR} \
		${STAGEDIR}${PG_RUNDIR}
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/postgrey_${i} \
		${STAGEDIR}${PREFIX}/etc/postfix/postgrey_${i}.sample
.endfor
	cd ${WRKSRC} && \
		${INSTALL_MAN} ${MANPAGES} ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

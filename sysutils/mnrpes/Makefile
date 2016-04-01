# $FreeBSD$

PORTNAME=	mnrpes
PORTVERSION=	2014041501
CATEGORIES=	sysutils

MAINTAINER=	robak@FreeBSD.org
COMMENT=	MCollective and Rufus scheduler wrapper

LICENSE=	APACHE20

RUN_DEPENDS=	mcollective>=2:sysutils/mcollective \
		rubygem-rufus-scheduler>=0.1:devel/rubygem-rufus-scheduler

USE_RUBY=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	nullDowntimeLtd
GH_TAGNAME=	3f9942c

USE_RC_SUBR=	mnrpes_receiver \
		mnrpes_scheduler

PLIST_SUB+=	PORTNAME=${PORTNAME}

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}/output
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mnrpes-receiver.rb ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mnrpes-scheduler.rb ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mnrpes.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mnrpes/receiver.rb ${STAGEDIR}${RUBY_SITELIBDIR}/mnrpes/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mnrpes/scheduler.rb ${STAGEDIR}${RUBY_SITELIBDIR}/mnrpes/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mnrpes/output/flapjack.rb ${STAGEDIR}${RUBY_SITELIBDIR}/mnrpes/output/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mnrpes/output/nagios.rb ${STAGEDIR}${RUBY_SITELIBDIR}/mnrpes/output/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mnrpes/output/redis_status.rb ${STAGEDIR}${RUBY_SITELIBDIR}/mnrpes/output/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/mnrpes/output/stdout.rb ${STAGEDIR}${RUBY_SITELIBDIR}/mnrpes/output/
	${INSTALL_DATA} ${WRKSRC}/etc/checks.txt.dist ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/mnrpes-receiver.cfg.dist ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/mnrpes-scheduler.cfg.dist ${STAGEDIR}${ETCDIR}

post-install:
	${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}

.include <bsd.port.mk>

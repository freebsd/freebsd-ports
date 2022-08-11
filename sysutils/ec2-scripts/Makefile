PORTNAME=	ec2-scripts
PORTVERSION=	1.11
CATEGORIES=	sysutils

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Startup scripts for FreeBSD/EC2 environment

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	${LOCALBASE}/sbin/ebsnvme-id:sysutils/ebsnvme-id

USE_GITHUB=	YES
GH_ACCOUNT=	cperciva

NO_BUILD=	YES

RC_SCRIPTS=	ec2_bootmail \
		ec2_configinit \
		ec2_ephemeral_diskseen \
		ec2_ephemeral_swap \
		ec2_fetchkey \
		ec2_loghostkey
PLIST_FILES=	sbin/configinit

.for i in ${RC_SCRIPTS}
PLIST_FILES+=	etc/rc.d/$i
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/configinit.sh ${STAGEDIR}${PREFIX}/sbin/configinit

post-install:
.for i in ${RC_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/etc/rc.d/
.endfor

.include <bsd.port.mk>

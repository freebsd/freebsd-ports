PORTNAME=	ebsnvme-id
DISTVERSION=	1.0.4
CATEGORIES=	sysutils

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Exposes information about NVMe disks on EC2
WWW=		https://github.com/cperciva/ebsnvme-id

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		uidfix

USE_GITHUB=	YES
GH_ACCOUNT=	cperciva

MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man

PLIST_FILES=	etc/rc.d/dev_aws_disk		\
		etc/devd/dev-aws-disk.conf	\
		sbin/ebsnvme			\
		sbin/ebsnvme-id			\
		sbin/ebsnvme-stats		\
		share/man/man8/ebsnvme.8.gz	\
		share/man/man8/ebsnvme-id.8.gz	\
		share/man/man8/ebsnvme-stats.8.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKSRC}/dev-aws-disk.conf ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_SCRIPT} ${WRKSRC}/dev_aws_disk ${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>

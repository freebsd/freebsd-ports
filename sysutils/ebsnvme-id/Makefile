# $FreeBSD$

PORTNAME=	ebsnvme-id
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Exposes information about NVMe disks on EC2

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USE_GITHUB=	YES
GH_ACCOUNT=	cperciva

PLIST_FILES=	etc/rc.d/dev_aws_disk		\
		etc/devd/dev-aws-disk.conf	\
		sbin/ebsnvme-id			\
		man/man8/ebsnvme-id.8.gz

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_DATA} ${WRKSRC}/dev-aws-disk.conf ${STAGEDIR}${PREFIX}/etc/devd
	${INSTALL_SCRIPT} ${WRKSRC}/dev_aws_disk ${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>

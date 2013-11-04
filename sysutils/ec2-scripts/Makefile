# Created by: Colin Percival
# $FreeBSD$

PORTNAME=	ec2-scripts
PORTVERSION=	1.6
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsd-ec2-dist.s3.amazonaws.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Startup scripts for FreeBSD/EC2 environment

LICENSE=	BSD

OPTIONS_DEFINE=	NOFIRSTBOOT
NOFIRSTBOOT_DESC=	Use old (pre-firstboot support) version of scripts

NO_BUILD=	YES
NO_INSTALL=	YES

RC_SCRIPTS=	ec2_bootmail ec2_ephemeralswap ec2_fetchkey ec2_loghostkey

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOFIRSTBOOT}
PORTVERSION=	1.5
PORTREVISION=	1
RC_SCRIPTS+=	ec2_firstboot panicmail
.endif

.for i in ${RC_SCRIPTS}
PLIST_FILES+=	etc/rc.d/$i
.endfor

post-install:
.for i in ${RC_SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/etc/rc.d/
.endfor

.include <bsd.port.mk>

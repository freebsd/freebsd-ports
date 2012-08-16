# New ports collection makefile for:		FreeBSD/EC2 startup scripts
# Date created:					2012-08-14
# Whom:						Colin Percival
#
# $FreeBSD$
#

PORTNAME=	ec2-scripts
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://freebsd-ec2-dist.s3.amazonaws.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cperciva@freebsd.org
COMMENT=	Startup scripts for FreeBSD/EC2 environment

NO_BUILD=	YES
NO_INSTALL=	YES

RC_SCRIPTS=	ec2_bootmail ec2_ephemeralswap ec2_fetchkey	\
		ec2_firstboot ec2_loghostkey panicmail

.for i in ${RC_SCRIPTS}
PLIST_FILES+=	etc/rc.d/$i
.endfor

post-install:
	@for i in ${RC_SCRIPTS}; do	\
		${INSTALL_SCRIPT} ${WRKSRC}/$${i} ${PREFIX}/etc/rc.d/$${i}; \
	done

.include <bsd.port.mk>

# Created by: stas
# $FreeBSD$

PORTNAME=	data
PORTVERSION=	0.6
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
PKGNAMEPREFIX=	devcpu-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intel and AMD CPUs microcode updates

USE_BZIP2=	yes
NO_BUILD=	yes

ONLY_FOR_ARCHS=	i386 amd64

NO_STAGE=	yes
.include <bsd.port.pre.mk>

DATADIR=	${PREFIX}/share/cpucontrol

USE_RC_SUBR=	microcode_update

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${DATADIR}/
	@${TOUCH} ${DATADIR}/.do_not_delete

post-install:
	@${FIND} -ds ${DATADIR}/ ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/${DATADIR:S,^${PREFIX},,}" >> ${TMPPLIST}

.include <bsd.port.post.mk>

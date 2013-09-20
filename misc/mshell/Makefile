# Created by: jmz
# $FreeBSD$

PORTNAME=	mshell
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz
DISTFILES=	7432.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unix menuing shell

NO_WRKSUBDIR=	yes
MAN1=		mshell.1

NO_STAGE=	yes
do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	zcat ${DISTDIR}/${DISTFILES} |(cd ${WRKDIR}; \
	${AWK} '{if (/^#!/) x++} {if(x) print $$0'}| ${SH})

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>

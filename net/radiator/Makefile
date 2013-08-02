# Created by: shan
# $FreeBSD$

PORTNAME=	Radiator
PORTVERSION=	4.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# fetch manually
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Radiator Radius Server by Open System Consultants

OPTIONS_DEFINE=	MYSQL
MYSQL_DESC=	MySQL support

USES=		perl5
USE_PERL5=	configure

RESTRICTED=	Commercial software

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=		will not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the UNIX version after\
		purchasing the license at: http://www.open.com.au/ \
		- once ${DISTFILES} has been downloaded, move it to\
		${DISTDIR}/${DIST_SUBDIR} and then restart this build. \
		(optionally download patches-${PORTVERSION}.tar.gz to the \
		same directory as well)
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

pre-configure:
.if exists(${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz)
	${TAR} -xvzf ${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz -C ${WRKSRC}
.endif

.include <bsd.port.post.mk>

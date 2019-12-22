# Created by: shan
# $FreeBSD$

PORTNAME=	Radiator
PORTVERSION=	4.24
CATEGORIES=	net
DISTNAME=	${PORTNAME}-${PORTVERSION}-1
MASTER_SITES=	# fetch manually

DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	lyngbol@wheel.dk
COMMENT=	Radiator Radius Server by Open System Consultants

LICENSE=	radiator
LICENSE_NAME=	Radiator
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell

OPTIONS_DEFINE=	MYSQL
MYSQL_DESC=	MySQL support

USES=		perl5 tar:tgz
USE_PERL5=	configure
USE_RC_SUBR=	radiator

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
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif

pre-configure:
.if exists(${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz)
	${TAR} -xvzf ${DISTDIR}/${DIST_SUBDIR}/patches-${PORTVERSION}.tar.gz -C ${WRKSRC}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/radius.cfg

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/radiator
	${RM} ${STAGEDIR}${PREFIX}/lib/perl5/site_perl/radhostname.pl
	${INSTALL_DATA} ${WRKSRC}/radius.cfg ${STAGEDIR}${PREFIX}/etc/radiator/radius.cfg.sample
	${INSTALL_DATA} ${WRKSRC}/dictionary ${STAGEDIR}${PREFIX}/etc/radiator
	${INSTALL_DATA} ${WRKSRC}/dictionary.ascend ${STAGEDIR}${PREFIX}/etc/radiator
	${INSTALL_DATA} ${WRKSRC}/dictionary.cisco-vpn ${STAGEDIR}${PREFIX}/etc/radiator
	${INSTALL_DATA} ${WRKSRC}/dictionary.sip ${STAGEDIR}${PREFIX}/etc/radiator

.include <bsd.port.post.mk>

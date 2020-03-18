# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	rancid
PORTVERSION=	3.12
PORTREVISION=	0
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/rancid/
PKGNAMESUFFIX=	3

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Really Awesome New Cisco confIg Differ

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libexpect.so:lang/expect
RUN_DEPENDS=	p5-LockFile-Simple>=0:devel/p5-LockFile-Simple

USES=		gmake perl5 shebangfix
perl_OLD_CMD=	@PERLV_PATH@
SHEBANG_FILES=	bin/*

USERS=		rancid
GROUPS=		rancid

SUB_FILES=	pkg-message 200.rancid
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=${LOCALBASE}/var/${PORTNAME}/ \
		--bindir=${LOCALBASE}/libexec/${PORTNAME}/ \
		--sysconfdir=${LOCALBASE}/etc/${PORTNAME}/

OLDCONFIG_FILE1=	bin/env
OLDCONFIG_FILE2=	util/lg/lg.conf
NEWERCONFIG_FILE1=	etc/rancid.conf
NEWERCONFIG_FILE2=	etc/lg.conf
NEWCONFIG_FILES=	rancid.conf lg.conf

OPTIONS_SINGLE=		SCM

OPTIONS_SINGLE_SCM=	CVS SVN GIT

OPTIONS_DEFINE=		COMWARE
OPTIONS_DEFAULT=	CVS

COMWARE_DESC=		Add experimental support for Comware devices
CVS_DESC=		Use CVS as the means of version control
SVN_DESC=		Use Subversion as the means of version control
GIT_DESC=		Use Git as the means of version control

CVS_RUN_DEPENDS=	cvs:devel/cvs
CVS_CONFIGURE_ON=	--without-svn

SVN_RUN_DEPENDS=	svn:devel/subversion
SVN_CONFIGURE_ON=	--with-svn

GIT_RUN_DEPENDS=	git:devel/git
GIT_CONFIGURE_ON=	--with-git

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMWARE}
PLIST_SUB+=	COMWARE=""
.else
PLIST_SUB+=	COMWARE="@comment "
.endif

pre-everything::
	@ ${ECHO} "Make sure your rancid repository is quiet before upgrading; disable rancid cron jobs"

post-patch:
.if ${PORT_OPTIONS:MCOMWARE}
	${CAT} ${FILESDIR}/comware_types.conf >> ${WRKSRC}/etc/rancid.types.base
	${SED} -e 's/@VERSION@/${PORTVERSION}/g' ${FILESDIR}/cmwlogin.in > ${WRKDIR}/cmwlogin
	${SED} -e 's/@VERSION@/${PORTVERSION}/g' ${FILESDIR}/cmw.pm.in > ${WRKDIR}/cmw.pm
.endif
	${REINPLACE_CMD} "s|par.1|rancid-par.1|" ${WRKSRC}/man/Makefile.in
	${MV} ${WRKSRC}/man/par.1 ${WRKSRC}/man/rancid-par.1
	${REINPLACE_CMD} 's|uid=`perl|uid=`${PERL}|' ${WRKSRC}/etc/rancid.conf.sample.in

post-install:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/periodic/hourly
	${INSTALL_SCRIPT} ${WRKDIR}/200.rancid ${STAGEDIR}${LOCALBASE}/etc/periodic/hourly
	${LN} -s ${LOCALBASE}/libexec/${PORTNAME}/rancid-cvs ${STAGEDIR}${LOCALBASE}/bin
	${LN} -s ${LOCALBASE}/libexec/${PORTNAME}/rancid-run ${STAGEDIR}${LOCALBASE}/bin
.if ${PORT_OPTIONS:MCOMWARE}
	${INSTALL_DATA} ${WRKDIR}/cmw.pm ${STAGEDIR}/${LOCALBASE}/lib/rancid
	${INSTALL_SCRIPT} ${WRKDIR}/cmwlogin ${STAGEDIR}/${LOCALBASE}/libexec/rancid
.endif
.for file in ${NEWCONFIG_FILES}
	@ if [ -f ${LOCALBASE}/etc/${PORTNAME}/${file} ] ; then \
	${ECHO} "WARNING: *** new ${file} file is installed as ${LOCALBASE}/rancid/${file}.sample"; \
	${ECHO} "       : *** review ${file}.sample for new/deprecated switches or install in place ${file}";  \
	fi
.endfor
	@ if [ -f ${LOCALBASE}/rancid/${NEWERCONFIG_FILE1} ] ; then \
	${ECHO} "WARNING: *** ${LOCALBASE}/rancid/${NEWERCONFIG_FILE1} has been replaced with "; \
	${ECHO} "       : *** ${LOCALBASE}/etc/${PORTNAME}/rancid.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${LOCALBASE}/rancid/${NEWERCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** ${LOCALBASE}/rancid/${NEWERCONFIG_FILE2} has been replaced with "; \
	${ECHO} "       : *** ${LOCALBASE}/etc/${PORTNAME}/lg.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${LOCALBASE}/rancid/${NEWERCONFIG_FILE1} -o \
	-f ${LOCALBASE}/rancid/${NEWERCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** New CVS Repository will be stored ${LOCALBASE}/var/${PORTNAME}/ "; \
	${ECHO} "       : *** Copy the repository if you want to keep the history "; \
	fi

	@ if [ -f ${LOCALBASE}/rancid/${OLDCONFIG_FILE1} ] ; then \
	${ECHO} "WARNING: *** ${LOCALBASE}/rancid/${OLDCONFIG_FILE1} has been replaced with "; \
	${ECHO} "       : *** ${LOCALBASE}/etc/${PORTNAME}/rancid.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${LOCALBASE}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** ${LOCALBASE}/rancid/${OLDCONFIG_FILE2} has been replaced with "; \
	${ECHO} "       : *** ${LOCALBASE}/etc/${PORTNAME}/lg.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${LOCALBASE}/rancid/${OLDCONFIG_FILE1} -o \
	-f ${LOCALBASE}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** New VCS Repository will be stored ${LOCALBASE}/rancid/var "; \
	${ECHO} "       : *** Copy the repository if you want to keep the history "; \
	fi

.include <bsd.port.mk>

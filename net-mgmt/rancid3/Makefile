# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	rancid
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.shrubbery.net/pub/rancid/
PKGNAMESUFFIX=	3

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Really Awesome New Cisco confIg Differ

LIB_DEPENDS=	libexpect.so:lang/expect
RUN_DEPENDS=	p5-LockFile-Simple>=0:devel/p5-LockFile-Simple

USES=		gmake perl5 shebangfix
perl_OLD_CMD=	@PERLV_PATH@
SHEBANG_FILES=	bin/*

USERS=		rancid
GROUPS=		rancid

SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/var/${PORTNAME}/ \
		--bindir=${PREFIX}/libexec/${PORTNAME}/ \
		--sysconfdir=${PREFIX}/etc/${PORTNAME}/

OLDCONFIG_FILE1=	bin/env
OLDCONFIG_FILE2=	util/lg/lg.conf
NEWERCONFIG_FILES1=	etc/rancid.conf
NEWERCONFIG_FILES2=	etc/lg.conf
NEWCONFIG_FILES=	rancid.conf lg.conf

OPTIONS_DEFINE=		SVN
OPTIONS_DEFAULT=

SVN_DESC=		Use Subversion instead of CVS

CONFLICTS=	rancid-[0-9]*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVN}
CONFIGURE_ARGS+=	--with-svn
BUILD_DEPENDS+=		svn:devel/subversion
.else
CONFIGURE_ARGS+=	--without-svn
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
RUN_DEPENDS+=	cvs>0:devel/cvs
.endif
.endif

pre-everything::
	@ ${ECHO} "Make sure your rancid repository is quiet before upgrading; disable rancid cron jobs"

post-patch:
	${REINPLACE_CMD} "s|par.1|rancid-par.1|" ${WRKSRC}/man/Makefile.in
	${MV} ${WRKSRC}/man/par.1 ${WRKSRC}/man/rancid-par.1

post-install:
	${LN} -s ${PREFIX}/libexec/${PORTNAME}/rancid-cvs ${STAGEDIR}${PREFIX}/bin
	${LN} -s ${PREFIX}/libexec/${PORTNAME}/rancid-run ${STAGEDIR}${PREFIX}/bin
.for file in ${NEWCONFIG_FILES}
	@ if [ -f ${PREFIX}/etc/${PORTNAME}/${file} ] ; then \
	${ECHO} "WARNING: *** new ${file} file is installed as ${PREFIX}/rancid/${file}.sample"; \
	${ECHO} "       : *** review ${file}.sample for new/deprecated switches or install in place ${file}";  \
	fi
.endfor
	@ if [ -f ${PREFIX}/rancid/${NEWERCONFIG_FILE1} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${NEWERCONFIG_FILE1} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/rancid.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${NEWERCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${NEWERCONFIG_FILE2} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/lg.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${NEWERCONFIG_FILE1} -o \
	-f ${PREFIX}/rancid/${NEWERCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** New CVS Repository will be stored ${PREFIX}/var/${PORTNAME}/ "; \
	${ECHO} "       : *** Copy the repository if you want to keep the history "; \
	fi

	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE1} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${OLDCONFIG_FILE1} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/rancid.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** ${PREFIX}/rancid/${OLDCONFIG_FILE2} has been replaced with "; \
	${ECHO} "       : *** ${PREFIX}/etc/${PORTNAME}/lg.conf. Merge from sample and old file "; \
	fi
	@ if [ -f ${PREFIX}/rancid/${OLDCONFIG_FILE1} -o \
	-f ${PREFIX}/rancid/${OLDCONFIG_FILE2} ] ; then \
	${ECHO} "WARNING: *** New CVS Repository will be stored ${PREFIX}/rancid/var "; \
	${ECHO} "       : *** Copy the repository if you want to keep the history "; \
	fi

.include <bsd.port.mk>

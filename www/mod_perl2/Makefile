# New ports collection makefile for:	mod_perl2
# Date created:				February 13th 2003
# Whom:					Lars Eggert <larse@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	mod_perl
PORTVERSION=	2.0.4
PORTREVISION=	2
PORTEPOCH=	3
CATEGORIES=	www perl5
MASTER_SITES=	http://perl.apache.org/dist/ \
		http://perl.apache.org/dist/old/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Embeds a Perl interpreter in the Apache2 server

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BSD/Resource.pm:${PORTSDIR}/devel/p5-BSD-Resource
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

SUB_FILES=	pkg-message
SUB_LIST=	APACHEMODDIR=${APACHEMODDIR}
USE_APACHE=	2.0+
PERL_CONFIGURE=	5.8.0+
GMAKE=		yes

# Using apxs in this way is problematic if apache2 is installed under a
# different PREFIX than mod_perl2, because the mod_perl2 installation will
# use paths returned by apxs to install some components. Fixes welcome.
CONFIGURE_ARGS=	MP_APXS=${LOCALBASE}/sbin/apxs PREFIX=${PREFIX}

MAN3=		APR.3 APR::Base64.3 APR::Brigade.3 APR::Bucket.3 \
		APR::BucketAlloc.3 APR::BucketType.3 APR::Const.3 \
		APR::Date.3 APR::Error.3 APR::Finfo.3 APR::IpSubnet.3 \
		APR::OS.3 APR::PerlIO.3 APR::Pool.3 APR::SockAddr.3 \
		APR::Socket.3 APR::Status.3 APR::String.3 APR::Table.3 \
		APR::ThreadMutex.3 APR::URI.3 APR::UUID.3 APR::Util.3 \
		Apache2::Access.3 Apache2::Build.3 Apache2::CmdParms.3 \
		Apache2::Command.3 Apache2::Connection.3 Apache2::Const.3 \
		Apache2::Directive.3 Apache2::Filter.3 Apache2::FilterRec.3 \
		Apache2::HookRun.3 Apache2::Log.3 Apache2::MPM.3 \
		Apache2::Module.3 Apache2::PerlSections.3 Apache2::Process.3 \
		Apache2::RequestIO.3 Apache2::RequestRec.3 \
		Apache2::RequestUtil.3 Apache2::Resource.3 \
		Apache2::Response.3 Apache2::ServerRec.3 \
		Apache2::ServerUtil.3 Apache2::SizeLimit.3 Apache2::Status.3 \
		Apache2::SubProcess.3 Apache2::SubRequest.3 Apache2::URI.3 \
		Apache2::Util.3 Apache2::compat.3 Apache2::porting.3 \
		Apache::Test.3 Apache::TestConfig.3 Apache::TestMB.3 \
		Apache::TestMM.3 Apache::TestReport.3 Apache::TestRequest.3 \
		Apache::TestRun.3 Apache::TestRunPHP.3 Apache::TestRunPerl.3 \
		Apache::TestServer.3 Apache::TestSmoke.3 Apache::TestTrace.3 Apache::TestUtil.3 \
		Bundle::Apache2.3 Bundle::ApacheTest.3 ModPerl::BuildMM.3 \
		ModPerl::CScan.3 ModPerl::Code.3 ModPerl::Config.3 \
		ModPerl::Const.3 ModPerl::Global.3 ModPerl::MM.3 \
		ModPerl::MethodLookup.3 ModPerl::PerlRun.3 \
		ModPerl::PerlRunPrefork.3 ModPerl::Registry.3 \
		ModPerl::RegistryBB.3 ModPerl::RegistryCooker.3 \
		ModPerl::RegistryLoader.3 ModPerl::RegistryPrefork.3 \
		ModPerl::Util.3 mod_perl2.3 Apache2::ConnectionUtil.3 \
		APR::ThreadRWLock.3

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/apr-1/apr.h)
APR_H=		${LOCALBASE}/include/apr-1/apr.h
APR_MAJ_V!=	${ECHO_CMD} `${LOCALBASE}/bin/apr-1-config --version | ${SED} -e 's,\..*,,'`
.elif exists(${LOCALBASE}/include/apr-0/apr.h)
APR_H=		${LOCALBASE}/include/apr-0/apr.h
APR_MAJ_V!=	${ECHO_CMD} `${LOCALBASE}/bin/apr-config --version | ${SED} -e 's,\..*,,'`
.endif

.if defined(APR_H)
APR_HAS_THREADS!=	${ECHO_CMD} `${GREP} -c 'APR_HAS_THREADS *1' ${APR_H}`
.else
APR_HAS_THREADS=	0
.endif

.if ${APR_HAS_THREADS} == 1
PLIST_SUB+=	THREADMUTEX=""
PLIST_SUB+=	THREADRWLOCK=""
.else
PLIST_SUB+=	THREADMUTEX="@comment "
PLIST_SUB+=	THREADRWLOCK="@comment "
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "Note, Aapche(2)::Reload was mistakenly ommited from ${PORTVERSION}"
	@${ECHO} "cd ${PORTSDIR}/www/p5-Apache-Reload ; ${MAKE} install"
	@${ECHO} "After installing mod_perl"
	@${ECHO} "This will be fixed in the next version...."
	@${ECHO} ""

pre-configure:
	${RM} ${WRKSRC}/lib/ModPerl/BuildMM.pm.orig
	${RM} ${WRKSRC}/lib/Apache2/Status.pm.orig

post-install:
	${MKDIR} ${PREFIX}/${APACHEINCLUDEDIR}/modules/perl
	${INSTALL_DATA} ${WRKSRC}/src/modules/perl/*.h \
		${PREFIX}/${APACHEINCLUDEDIR}/modules/perl
	${INSTALL_DATA} ${WRKSRC}/xs/*.h ${PREFIX}/${APACHEINCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/xs/APR/PerlIO/*.h ${PREFIX}/${APACHEINCLUDEDIR}
	${MKDIR} ${PREFIX}/${APACHEMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/modules/perl/mod_perl.so \
		${PREFIX}/${APACHEMODDIR}/mod_perl.so
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

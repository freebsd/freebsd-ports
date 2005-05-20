# New ports collection makefile for:	mod_perl2
# Date created:				February 13th 2003
# Whom:					Lars Eggert <larse@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	mod_perl
PORTVERSION=	2.0.0
PORTEPOCH=	2
CATEGORIES=	www perl5
MASTER_SITES=	http://perl.apache.org/dist/ \
		http://perl.apache.org/dist/old/
PKGNAMESUFFIX=	2

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	Embeds a Perl interpreter in the Apache2 server

USE_APACHE=	yes
WITH_APACHE2=	yes
PERL_CONFIGURE=	yes
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
		Apache2::Reload.3 Apache2::RequestIO.3 Apache2::RequestRec.3 \
		Apache2::RequestUtil.3 Apache2::Resource.3 \
		Apache2::Response.3 Apache2::ServerRec.3 \
		Apache2::ServerUtil.3 Apache2::SizeLimit.3 Apache2::Status.3 \
		Apache2::SubProcess.3 Apache2::SubRequest.3 Apache2::URI.3 \
		Apache2::Util.3 Apache2::compat.3 Apache2::porting.3 \
		Apache::Test.3 Apache::TestConfig.3 Apache::TestMB.3 \
		Apache::TestMM.3 Apache::TestReport.3 Apache::TestRequest.3 \
		Apache::TestRun.3 Apache::TestRunPHP.3 Apache::TestRunPerl.3 \
		Apache::TestSmoke.3 Apache::TestTrace.3 Apache::TestUtil.3 \
		Bundle::Apache2.3 Bundle::ApacheTest.3 ModPerl::BuildMM.3 \
		ModPerl::CScan.3 ModPerl::Code.3 ModPerl::Config.3 \
		ModPerl::Const.3 ModPerl::Global.3 ModPerl::MM.3 \
		ModPerl::MethodLookup.3 ModPerl::PerlRun.3 \
		ModPerl::PerlRunPrefork.3 ModPerl::Registry.3 \
		ModPerl::RegistryBB.3 ModPerl::RegistryCooker.3 \
		ModPerl::RegistryLoader.3 ModPerl::RegistryPrefork.3 \
		ModPerl::Util.3 mod_perl2.3

pre-everything::
	@${ECHO} "************************************************************"
	@${ECHO} "NOTE: Version 2.0.0-RC5 and higher of ${PORTNAME}"
	@${ECHO} "      significantly change the API - old code *will* break!"
	@${ECHO} "      See http://perl.apache.org/docs/2.0/rename.html"
	@${ECHO} ""
	@${ECHO} "Hit Ctrl-C to abort now, if this is of concern."
	@${ECHO} "************************************************************"
	@sleep 10

.include <bsd.port.pre.mk>

# it is time to require perl 5.8.x
.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

post-install:
	${MKDIR} ${PREFIX}/include/apache2/modules/perl
	${INSTALL_DATA} ${WRKSRC}/src/modules/perl/*.h \
		${PREFIX}/include/apache2/modules/perl
	${INSTALL_DATA} ${WRKSRC}/xs/*.h ${PREFIX}/include/apache2
	${INSTALL_DATA} ${WRKSRC}/xs/APR/PerlIO/*.h ${PREFIX}/include/apache2
	${MKDIR} ${PREFIX}/libexec/apache2
	${INSTALL_PROGRAM} ${WRKSRC}/src/modules/perl/mod_perl.so \
		${PREFIX}/libexec/apache2/mod_perl.so
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

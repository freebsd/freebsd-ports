# New ports collection makefile for:	psgconf
# Date created:				17 Feb 2004
# Whom:						Jim Pirzyk <pirzyk@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	psgconf
PORTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp-dev.cites.uiuc.edu/pub/psgconf/

MAINTAINER=	pirzyk@freebsd.org
COMMENT=	Controls system configuration

BUILD_DEPENDS=	${SITE_PERL}/Config/Objective.pm:${PORTSDIR}/devel/p5-Config-Objective \
 	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
 	p5-NetAddr-IP>0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
	${SITE_PERL}/${PERL_ARCH}/Proc/ProcessTable/Process.pm:${PORTSDIR}/devel/p5-Proc-ProcessTable \
	${SITE_PERL}/${PERL_ARCH}/Unix/Mknod.pm:${PORTSDIR}/sysutils/p5-Unix-Mknod \
	${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
	${SITE_PERL}/${PERL_ARCH}/version.pm:${PORTSDIR}/devel/p5-version \
	${SITE_PERL}/Text/Diff.pm:${PORTSDIR}/textproc/p5-Text-Diff
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN1=		psgconf.1
MAN3=		PSGConf.3 \
		PSGConf::Action.3 \
		PSGConf::Action::ChGrp.3 \
		PSGConf::Action::ChMod.3 \
		PSGConf::Action::ChOwn.3 \
		PSGConf::Action::CopyFile.3 \
		PSGConf::Action::CreateFile.3 \
		PSGConf::Action::Crontab.3 \
		PSGConf::Action::File.3 \
		PSGConf::Action::GenerateFile.3 \
		PSGConf::Action::GenerateFile::AppConfig.3 \
		PSGConf::Action::GenerateFile::BSD_exports.3 \
		PSGConf::Action::GenerateFile::EnvFile.3 \
		PSGConf::Action::GenerateFile::Literal.3 \
		PSGConf::Action::GenerateFile::RC_Script.3 \
		PSGConf::Action::GenerateFile::SASL_conf.3 \
		PSGConf::Action::GenerateFile::TLI_hosts.3 \
		PSGConf::Action::GenerateFile::auto_direct.3 \
		PSGConf::Action::GenerateFile::dfstab.3 \
		PSGConf::Action::GenerateFile::dsm_opt.3 \
		PSGConf::Action::GenerateFile::dsm_sys.3 \
		PSGConf::Action::GenerateFile::etc_cshrc.3 \
		PSGConf::Action::GenerateFile::etc_exports.3 \
		PSGConf::Action::GenerateFile::etc_group.3 \
		PSGConf::Action::GenerateFile::etc_master_passwd.3 \
		PSGConf::Action::GenerateFile::etc_passwd.3 \
		PSGConf::Action::GenerateFile::etc_profile.3 \
		PSGConf::Action::GenerateFile::etc_rpc.3 \
		PSGConf::Action::GenerateFile::etc_security_passwd.3 \
		PSGConf::Action::GenerateFile::etc_services.3 \
		PSGConf::Action::GenerateFile::etc_shadow.3 \
		PSGConf::Action::GenerateFile::etc_system.3 \
		PSGConf::Action::GenerateFile::etc_user_attr.3 \
		PSGConf::Action::GenerateFile::ftpaccess.3 \
		PSGConf::Action::GenerateFile::hosts.3 \
		PSGConf::Action::GenerateFile::hosts_allow.3 \
		PSGConf::Action::GenerateFile::httpd_conf.3 \
		PSGConf::Action::GenerateFile::inetd_conf.3 \
		PSGConf::Action::GenerateFile::logadm.3 \
		PSGConf::Action::GenerateFile::logrotate.3 \
		PSGConf::Action::GenerateFile::ld_so_config.3 \
		PSGConf::Action::GenerateFile::mime_types.3 \
		PSGConf::Action::GenerateFile::named_conf.3 \
		PSGConf::Action::GenerateFile::netmasks.3 \
		PSGConf::Action::GenerateFile::newsyslog.3 \
		PSGConf::Action::GenerateFile::nsswitch_conf.3 \
		PSGConf::Action::GenerateFile::ntp_conf.3 \
		PSGConf::Action::GenerateFile::pam_conf.3 \
		PSGConf::Action::GenerateFile::pam_file.3 \
		PSGConf::Action::GenerateFile::printcap.3 \
		PSGConf::Action::GenerateFile::qpopper_conf.3 \
		PSGConf::Action::GenerateFile::resolv_conf.3 \
		PSGConf::Action::GenerateFile::sendmail_aliases.3 \
		PSGConf::Action::GenerateFile::sendmail_cf.3 \
		PSGConf::Action::GenerateFile::sendmail_map.3 \
		PSGConf::Action::GenerateFile::sendmail_mc.3 \
		PSGConf::Action::GenerateFile::sendmail_trusted_users.3 \
		PSGConf::Action::GenerateFile::sshd_config.3 \
		PSGConf::Action::GenerateFile::sudoers.3 \
		PSGConf::Action::GenerateFile::syslog_conf.3 \
		PSGConf::Action::GenerateFile::tsm_inclexcl.3 \
		PSGConf::Action::GenerateFile::workers_properties.3 \
		PSGConf::Action::GenerateFile::xinetd_conf.3 \
		PSGConf::Action::HomeDir.3 \
		PSGConf::Action::lpadmin.3 \
		PSGConf::Action::MkDir.3 \
		PSGConf::Action::MkNod.3 \
		PSGConf::Action::ModifyFile.3 \
		PSGConf::Action::PackageManager.3 \
		PSGConf::Action::PackageManager::Encap.3 \
		PSGConf::Action::PackageManager::FTPArchive.3 \
		PSGConf::Action::PackageManager::FreeBSD.3 \
		PSGConf::Action::PackageManager::FreeBSD::Packages.3 \
		PSGConf::Action::PackageManager::FreeBSD::Ports.3 \
		PSGConf::Action::PackageManager::RedHat::RHN.3 \
		PSGConf::Action::PackageManager::RedHat::RPMS.3 \
		PSGConf::Action::PackageManager::RedHat::Yum.3 \
		PSGConf::Action::PackageManager::Solaris.3 \
		PSGConf::Action::Remove.3 \
		PSGConf::Action::RemoveCrontab.3 \
		PSGConf::Action::RestartDaemon.3 \
		PSGConf::Action::RPMImportGPGKey.3 \
		PSGConf::Action::RunCommand.3 \
		PSGConf::Action::Symlink.3 \
		PSGConf::Action::TouchFile.3 \
		PSGConf::Action::UntarFile.3 \
		PSGConf::Action::svcs::addpg.3 \
		PSGConf::Action::svcs::import.3 \
		PSGConf::Action::svcs::setprop.3 \
		PSGConf::Control.3 \
		PSGConf::Control::AIX.3 \
		PSGConf::Control::AnonFTP.3 \
		PSGConf::Control::Apache.3 \
		PSGConf::Control::Apache::FastCGI.3 \
		PSGConf::Control::Apache::mod_jk.3 \
		PSGConf::Control::CachingDNS.3 \
		PSGConf::Control::Core.3 \
		PSGConf::Control::FreeBSD.3 \
		PSGConf::Control::InitScripts.3 \
		PSGConf::Control::Inittab.3 \
		PSGConf::Control::LogFiles.3 \
		PSGConf::Control::NFS_Client.3 \
		PSGConf::Control::NFS_Server.3 \
		PSGConf::Control::NTP.3 \
		PSGConf::Control::NameServiceSwitch.3 \
		PSGConf::Control::Network.3 \
		PSGConf::Control::PAM.3 \
		PSGConf::Control::Packages.3 \
		PSGConf::Control::PostgreSQL.3 \
		PSGConf::Control::Printers.3 \
		PSGConf::Control::RedHat.3 \
		PSGConf::Control::RPC.3 \
		PSGConf::Control::RPC::rstatd.3 \
		PSGConf::Control::Resolver.3 \
		PSGConf::Control::SASL.3 \
		PSGConf::Control::SharedLibrary.3 \
		PSGConf::Control::ShellStartupFiles.3 \
		PSGConf::Control::Shells.3 \
		PSGConf::Control::Solaris.3 \
		PSGConf::Control::TCPWrappers.3 \
		PSGConf::Control::TSM.3 \
		PSGConf::Control::Users.3 \
		PSGConf::Control::cron.3 \
		PSGConf::Control::dtlogin.3 \
		PSGConf::Control::inetd.3 \
		PSGConf::Control::motd.3 \
		PSGConf::Control::qpopper.3 \
		PSGConf::Control::sendmail.3 \
		PSGConf::Control::sshd.3 \
		PSGConf::Control::sudo.3 \
		PSGConf::Control::swatch.3 \
		PSGConf::Control::syslog.3 \
		PSGConf::Data.3 \
		PSGConf::Data::Boolean.3 \
		PSGConf::Data::ConfigError.3 \
		PSGConf::Data::Enum.3 \
		PSGConf::Data::FileTest.3 \
		PSGConf::Data::Hash.3 \
		PSGConf::Data::Integer.3 \
		PSGConf::Data::List.3 \
		PSGConf::Data::String.3 \
		PSGConf::Data::Table.3 \
		PSGConf::DataStore.3 \
		PSGConf::DataStore::AppConfig.3 \
		PSGConf::DataStore::ConfigFile.3 \
		PSGConf::DataStore::Storable.3 \
		PSGConf::Import::group_info.3 \
		PSGConf::Import::inittab.3 \
		PSGConf::Import::pkg_default_versions.3 \
		PSGConf::Import::ports.3 \
		PSGConf::Import::shells.3 \
		PSGConf::Import::user_info.3 \
		PSGConf::Util.3 \
		psgconf-intro.3

PKGINSTALL=	${WRKSRC}/postinstall
PKGDEINSTALL=	${WRKSRC}/postinstall

post-patch:
	${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
	-@${MKDIR} ${PREFIX}/etc
	@${CP} ${WRKSRC}/etc/psg.conf ${PREFIX}/etc/psg.conf.sample
	@${CP} ${WRKSRC}/etc/psgconf_modules ${PREFIX}/etc/psgconf_modules.sample
	PKG_PREFIX=${PREFIX} PKG_MGR=FreeBSD::Ports ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

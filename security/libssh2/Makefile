# New ports collection makefile for:	libssh2
# Date created:		2005-04-07
# Whom:			Alexander Leidinger <netchild@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	libssh2
PORTVERSION=	1.4.2
PORTEPOCH=	2
CATEGORIES=	security devel
MASTER_SITES=	http://www.libssh2.org/download/ \
		${MASTER_SITE_LOCAL:S,%SUBDIR%,sbz,}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	A library implementing the SSH2 protocol

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_OPENSSL=	yes
USE_AUTOTOOLS=	autoconf
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GCRYPT TRACE ZLIB
OPTIONS_DEFAULT=	ZLIB

GCRYPT_DESC=	Use libgcrypt instead of OpenSSL
TRACE_DESC=	Enable debug packet traces
ZLIB_DESC=	Enable compression

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTRACE}
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=	--with-libgcrypt -with-libgcrypt-prefix=${LOCALBASE} --without-openssl
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MZLIB}
CONFIGURE_ARGS+=	--with-libz
.else
CONFIGURE_ARGS+=	--without-libz
.endif

MAN3=	libssh2_agent_connect.3 \
	libssh2_agent_disconnect.3 \
	libssh2_agent_free.3 \
	libssh2_agent_get_identity.3 \
	libssh2_agent_init.3 \
	libssh2_agent_list_identities.3 \
	libssh2_agent_userauth.3 \
	libssh2_banner_set.3 \
	libssh2_base64_decode.3 \
	libssh2_channel_close.3 \
	libssh2_channel_direct_tcpip.3 \
	libssh2_channel_direct_tcpip_ex.3 \
	libssh2_channel_eof.3 \
	libssh2_channel_exec.3 \
	libssh2_channel_flush.3 \
	libssh2_channel_flush_ex.3 \
	libssh2_channel_flush_stderr.3 \
	libssh2_channel_forward_accept.3 \
	libssh2_channel_forward_cancel.3 \
	libssh2_channel_forward_listen.3 \
	libssh2_channel_forward_listen_ex.3 \
	libssh2_channel_free.3 \
	libssh2_channel_get_exit_signal.3 \
	libssh2_channel_get_exit_status.3 \
	libssh2_channel_handle_extended_data.3 \
	libssh2_channel_handle_extended_data2.3 \
	libssh2_channel_ignore_extended_data.3 \
	libssh2_channel_open_ex.3 \
	libssh2_channel_open_session.3 \
	libssh2_channel_process_startup.3 \
	libssh2_channel_read.3 \
	libssh2_channel_read_ex.3 \
	libssh2_channel_read_stderr.3 \
	libssh2_channel_receive_window_adjust.3 \
	libssh2_channel_receive_window_adjust2.3 \
	libssh2_channel_request_pty.3 \
	libssh2_channel_request_pty_ex.3 \
	libssh2_channel_request_pty_size.3 \
	libssh2_channel_request_pty_size_ex.3 \
	libssh2_channel_send_eof.3 \
	libssh2_channel_set_blocking.3 \
	libssh2_channel_setenv.3 \
	libssh2_channel_setenv_ex.3 \
	libssh2_channel_shell.3 \
	libssh2_channel_subsystem.3 \
	libssh2_channel_wait_closed.3 \
	libssh2_channel_wait_eof.3 \
	libssh2_channel_window_read.3 \
	libssh2_channel_window_read_ex.3 \
	libssh2_channel_window_write.3 \
	libssh2_channel_window_write_ex.3 \
	libssh2_channel_write.3 \
	libssh2_channel_write_ex.3 \
	libssh2_channel_write_stderr.3 \
	libssh2_channel_x11_req.3 \
	libssh2_channel_x11_req_ex.3 \
	libssh2_exit.3 \
	libssh2_free.3 \
	libssh2_hostkey_hash.3 \
	libssh2_init.3 \
	libssh2_keepalive_config.3 \
	libssh2_keepalive_send.3 \
	libssh2_knownhost_add.3 \
	libssh2_knownhost_addc.3 \
	libssh2_knownhost_check.3 \
	libssh2_knownhost_checkp.3 \
	libssh2_knownhost_del.3 \
	libssh2_knownhost_free.3 \
	libssh2_knownhost_get.3 \
	libssh2_knownhost_init.3 \
	libssh2_knownhost_readfile.3 \
	libssh2_knownhost_readline.3 \
	libssh2_knownhost_writefile.3 \
	libssh2_knownhost_writeline.3 \
	libssh2_poll.3 \
	libssh2_poll_channel_read.3 \
	libssh2_publickey_add.3 \
	libssh2_publickey_add_ex.3 \
	libssh2_publickey_init.3 \
	libssh2_publickey_list_fetch.3 \
	libssh2_publickey_list_free.3 \
	libssh2_publickey_remove.3 \
	libssh2_publickey_remove_ex.3 \
	libssh2_publickey_shutdown.3 \
	libssh2_scp_recv.3 \
	libssh2_scp_send.3 \
	libssh2_scp_send64.3 \
	libssh2_scp_send_ex.3 \
	libssh2_session_abstract.3 \
	libssh2_session_banner_get.3 \
	libssh2_session_banner_set.3 \
	libssh2_session_block_directions.3 \
	libssh2_session_callback_set.3 \
	libssh2_session_disconnect.3 \
	libssh2_session_disconnect_ex.3 \
	libssh2_session_flag.3 \
	libssh2_session_free.3 \
	libssh2_session_get_blocking.3 \
	libssh2_session_get_timeout.3 \
	libssh2_session_hostkey.3 \
	libssh2_session_init.3 \
	libssh2_session_init_ex.3 \
	libssh2_session_last_errno.3 \
	libssh2_session_last_error.3 \
	libssh2_session_method_pref.3 \
	libssh2_session_methods.3 \
	libssh2_session_set_blocking.3 \
	libssh2_session_set_timeout.3 \
	libssh2_session_startup.3 \
	libssh2_session_supported_algs.3 \
	libssh2_sftp_close.3 \
	libssh2_sftp_close_handle.3 \
	libssh2_sftp_closedir.3 \
	libssh2_sftp_fsetstat.3 \
	libssh2_sftp_fstat.3 \
	libssh2_sftp_fstat_ex.3 \
	libssh2_sftp_fstatvfs.3 \
	libssh2_sftp_get_channel.3 \
	libssh2_sftp_init.3 \
	libssh2_sftp_last_error.3 \
	libssh2_sftp_lstat.3 \
	libssh2_sftp_mkdir.3 \
	libssh2_sftp_mkdir_ex.3 \
	libssh2_sftp_open.3 \
	libssh2_sftp_open_ex.3 \
	libssh2_sftp_opendir.3 \
	libssh2_sftp_read.3 \
	libssh2_sftp_readdir.3 \
	libssh2_sftp_readdir_ex.3 \
	libssh2_sftp_readlink.3 \
	libssh2_sftp_realpath.3 \
	libssh2_sftp_rename.3 \
	libssh2_sftp_rename_ex.3 \
	libssh2_sftp_rewind.3 \
	libssh2_sftp_rmdir.3 \
	libssh2_sftp_rmdir_ex.3 \
	libssh2_sftp_seek.3 \
	libssh2_sftp_seek64.3 \
	libssh2_sftp_setstat.3 \
	libssh2_sftp_shutdown.3 \
	libssh2_sftp_stat.3 \
	libssh2_sftp_stat_ex.3 \
	libssh2_sftp_statvfs.3 \
	libssh2_sftp_symlink.3 \
	libssh2_sftp_symlink_ex.3 \
	libssh2_sftp_tell.3 \
	libssh2_sftp_tell64.3 \
	libssh2_sftp_unlink.3 \
	libssh2_sftp_unlink_ex.3 \
	libssh2_sftp_write.3 \
	libssh2_trace.3 \
	libssh2_trace_sethandler.3 \
	libssh2_userauth_authenticated.3 \
	libssh2_userauth_hostbased_fromfile.3 \
	libssh2_userauth_hostbased_fromfile_ex.3 \
	libssh2_userauth_keyboard_interactive.3 \
	libssh2_userauth_keyboard_interactive_ex.3 \
	libssh2_userauth_list.3 \
	libssh2_userauth_password.3 \
	libssh2_userauth_password_ex.3 \
	libssh2_userauth_publickey.3 \
	libssh2_userauth_publickey_fromfile.3 \
	libssh2_userauth_publickey_fromfile_ex.3 \
	libssh2_version.3

# allow maintainer to generate MAN3 manpages list (make extract is required before)
x-generate-man3:
	@(cd ${WRKSRC}/docs && ${LS} -1F *.3 | ${SORT} | ${CUT} -d '/' -f4 \
		| ${GREP} -v template)

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>

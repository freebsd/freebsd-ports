# New ports collection makefile for: ClearSilver
# Date created:                      17 April 2004
# Whom:                              thinker <thinker@branda.to>
# Whom:                              Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=	clearsilver
PORTVERSION=	0.9.14
CATEGORIES=	www
MASTER_SITES=	http://www.clearsilver.net/downloads/ \
		http://depot.fsck.ch/mirror/distfiles/

MAINTAINER=	ports@fsck.ch
COMMENT=	A fast, powerful, and language-neutral template system

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
MANCOMPRESSED=	no

CONFIGURE_ARGS=	--disable-apache --disable-perl --disable-ruby \
		--disable-java --disable-csharp

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--with-python=${PYTHON_CMD}
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
PKGNAMESUFFIX=	-python
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

MAN3=	cBroadcast.3 cCreate.3 cDestroy.3 cSignal.3 cWait.3 \
	cgi_cookie_authority.3 cgi_cookie_clear.3 cgi_cookie_set.3 \
	cgi_cs_init.3 cgi_debug_init.3 cgi_destroy.3 cgi_display.3 cgi_error.3 \
	cgi_filehandle.3 cgi_init.3 cgi_neo_error.3 cgi_output.3 cgi_parse.3 \
	cgi_redirect.3 cgi_redirect_uri.3 cgi_register_parse_cb.3 \
	cgi_url_escape.3 cgi_url_escape_more.3 cgi_url_unescape.3 \
	cgi_vredirect.3 cgiwrap_getenv.3 cgiwrap_init_emu.3 cgiwrap_init_std.3 \
	cgiwrap_iterenv.3 cgiwrap_putenv.3 cgiwrap_read.3 cgiwrap_write.3 \
	cgiwrap_writef.3 cgiwrap_writevf.3 cs_destroy.3 cs_dump.3 cs_init.3 \
	cs_parse_file.3 cs_parse_string.3 cs_register_strfunc.3 cs_render.3 \
	dictCleanup.3 dictCreate.3 dictDestroy.3 dictModifyValue.3 dictNext.3 \
	dictReleaseLock.3 dictRemove.3 dictSearch.3 dictSetValue.3 fCreate.3 \
	fDestroy.3 fFind.3 fLock.3 fUnlock.3 filter_create_fd.3 \
	filter_create_fp.3 filter_wait.3 hdf_copy.3 hdf_destroy.3 hdf_dump.3 \
	hdf_dump_format.3 hdf_dump_str.3 hdf_get_attr.3 hdf_get_child.3 \
	hdf_get_copy.3 hdf_get_int_value.3 hdf_get_node.3 hdf_get_obj.3 \
	hdf_get_value.3 hdf_get_valuef.3 hdf_get_valuevf.3 hdf_init.3 \
	hdf_obj_attr.3 hdf_obj_child.3 hdf_obj_name.3 hdf_obj_next.3 \
	hdf_obj_top.3 hdf_obj_value.3 hdf_read_string.3 \
	hdf_read_string_ignore.3 hdf_remove_tree.3 hdf_search_path.3 \
	hdf_set_attr.3 hdf_set_buf.3 hdf_set_copy.3 hdf_set_int_value.3 \
	hdf_set_symlink.3 hdf_set_value.3 hdf_set_valuef.3 hdf_sort_obj.3 \
	hdf_write_file.3 hdf_write_file_atomic.3 hdf_write_string.3 mCreate.3 \
	mDestroy.3 mLock.3 mUnlock.3 nerr_ignore.3 nerr_error_string.3 \
	nerr_error_traceback.3 nerr_handle.3 nerr_init.3 nerr_log_error.3 \
	nerr_match.3 nerr_pass.3 nerr_pass_ctx.3 nerr_raise.3 nerr_register.3 \
	skipDelete.3 skipFreeList.3 skipInsert.3 skipNewList.3 skipNext.3 \
	skipRelease.3 skipSearch.3 wdb_keys.3

.include <bsd.port.pre.mk>

post-patch:
	@# Remove CFLAGS when building the python module, pydistfile is used
	@# and will do the right thing.
	@${REINPLACE_CMD} -E 's,(\$$\(PYTHON\)),CFLAGS="" \1,g' ${WRKSRC}/python/Makefile
	@# insert -fPIC into CFLAGS to fix non-i386 builds
	@${REINPLACE_CMD} -e 's|= @CFLAGS@|= @CFLAGS@ -fPIC|g' ${WRKSRC}/rules.mk.in
	@# Avoid rebuilding man pages
	@${REINPLACE_CMD} -e 's,all man,all,g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|`$$python_bin -c "import site; print site.sitedirs\[0\]"`|"${PYTHON_SITELIBDIR}"|' ${WRKSRC}/configure

.include <bsd.port.post.mk>

# New ports collection makefile for:	mpich (portable mpi standard imp.)
# Date created:		2 May 1998
# Whom:                 dbader@ece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	mpich2
PORTVERSION=	1.0.3
CATEGORIES=	net parallel
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/	\
		http://www-unix.mcs.anl.gov/mpi/mpich/downloads/
DIST_SUBDIR=	mpich
#PATCH_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/mpich2-patch/
#PATCHFILES=

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A portable implementation of MPI-1 and MPI-2

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_JAVA	don't build MPE Jumpshot-4
# - WITHOUT_X11		disable MPE graphics routines
# - WITHOUT_F90		disable gfortran support
#-----------------------------------------------------------------------

USE_PYTHON=	yes
USE_PERL5_BUILD=yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-romio
CONFIGURE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" F77=${F77} FFLAGS=${FFLAGS}
FFLAGS?=	-O2
NOCCACHE=	yes
MAKE_ENV=	CCACHE_DISABLE=yes

NO_MTREE=	yes
INSTALLS_SHLIB=	yes

SUB_FILES=	pkg-message

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--disable-graphics
WITHOUT_JAVA=	yes
PLIST_SUB+=	X11="@comment "
.else
USE_XLIB=	yes
PLIST_SUB+=	X11=""
.endif

.if defined(WITHOUT_JAVA)
CONFIGURE_ARGS+=	--without-java
PLIST_SUB+=	JAVA="@comment "
.else
USE_JAVA=	yes
JAVA_VERSION=	1.4+
BUILD_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
RUN_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
PLIST_SUB+=	JAVA=""
.endif

.if defined(WITHOUT_F90)
CONFIGURE_ARGS+=	--disable-f90
PLIST_SUB+=	F90="@comment "
.else
F90=		gfortran41
BUILD_DEPENDS+=	${F90}:${PORTSDIR}/lang/gfortran
F90FLAGS+=	-ff2c
CONFIGURE_ENV+=	F90=${F90} F90FLAGS=${F90FLAGS}
PLIST_SUB+=	F90=""
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--without-docdir --without-htmldir
.else
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR} --with-htmldir=${DOCSDIR}
.endif

MAN1=		MPI.1 mpicc.1 mpicxx.1 mpiexec.1 mpif77.1 mpif90.1
MAN3=		MPI_Abort.3 MPI_Accumulate.3 MPI_Add_error_class.3		\
		MPI_Add_error_code.3 MPI_Add_error_string.3 MPI_Address.3	\
		MPI_Allgather.3 MPI_Allgatherv.3 MPI_Alloc_mem.3 MPI_Allreduce.3\
		MPI_Alltoall.3 MPI_Alltoallv.3 MPI_Alltoallw.3 MPI_Attr_delete.3\
		MPI_Attr_get.3 MPI_Attr_put.3 MPI_Barrier.3 MPI_Bcast.3		\
		MPI_Bsend.3 MPI_Bsend_init.3 MPI_Buffer_attach.3		\
		MPI_Buffer_detach.3 MPI_Cancel.3 MPI_Cart_coords.3		\
		MPI_Cart_create.3 MPI_Cart_get.3 MPI_Cart_map.3 MPI_Cart_rank.3	\
		MPI_Cart_shift.3 MPI_Cart_sub.3 MPI_Cartdim_get.3		\
		MPI_Close_port.3 MPI_Comm_accept.3 MPI_Comm_call_errhandler.3	\
		MPI_Comm_compare.3 MPI_Comm_connect.3 MPI_Comm_create.3		\
		MPI_Comm_create_errhandler.3 MPI_Comm_create_keyval.3		\
		MPI_Comm_delete_attr.3 MPI_Comm_disconnect.3 MPI_Comm_dup.3	\
		MPI_Comm_free.3 MPI_Comm_free_keyval.3 MPI_Comm_get_attr.3	\
		MPI_Comm_get_errhandler.3 MPI_Comm_get_name.3			\
		MPI_Comm_get_parent.3 MPI_Comm_group.3 MPI_Comm_join.3		\
		MPI_Comm_rank.3 MPI_Comm_remote_group.3 MPI_Comm_remote_size.3	\
		MPI_Comm_set_attr.3 MPI_Comm_set_errhandler.3			\
		MPI_Comm_set_name.3 MPI_Comm_size.3 MPI_Comm_spawn.3		\
		MPI_Comm_spawn_multiple.3 MPI_Comm_split.3 MPI_Comm_test_inter.3\
		MPI_Dims_create.3 MPI_Errhandler_create.3 MPI_Errhandler_free.3	\
		MPI_Errhandler_get.3 MPI_Errhandler_set.3 MPI_Error_class.3	\
		MPI_Error_string.3 MPI_Exscan.3 MPI_File_c2f.3			\
		MPI_File_call_errhandler.3 MPI_File_close.3			\
		MPI_File_create_errhandler.3 MPI_File_delete.3 MPI_File_f2c.3	\
		MPI_File_get_amode.3 MPI_File_get_atomicity.3			\
		MPI_File_get_byte_offset.3 MPI_File_get_errhandler.3		\
		MPI_File_get_group.3 MPI_File_get_info.3 MPI_File_get_position.3\
		MPI_File_get_position_shared.3 MPI_File_get_size.3		\
		MPI_File_get_type_extent.3 MPI_File_get_view.3 MPI_File_iread.3	\
		MPI_File_iread_at.3 MPI_File_iread_shared.3 MPI_File_iwrite.3	\
		MPI_File_iwrite_at.3 MPI_File_iwrite_shared.3 MPI_File_open.3	\
		MPI_File_preallocate.3 MPI_File_read.3 MPI_File_read_all.3	\
		MPI_File_read_all_begin.3 MPI_File_read_all_end.3		\
		MPI_File_read_at.3 MPI_File_read_at_all.3			\
		MPI_File_read_at_all_begin.3 MPI_File_read_at_all_end.3		\
		MPI_File_read_ordered.3 MPI_File_read_ordered_begin.3		\
		MPI_File_read_ordered_end.3 MPI_File_read_shared.3		\
		MPI_File_seek.3 MPI_File_seek_shared.3 MPI_File_set_atomicity.3	\
		MPI_File_set_errhandler.3 MPI_File_set_info.3			\
		MPI_File_set_size.3 MPI_File_set_view.3 MPI_File_sync.3		\
		MPI_File_write.3 MPI_File_write_all.3 MPI_File_write_all_begin.3\
		MPI_File_write_all_end.3 MPI_File_write_at.3			\
		MPI_File_write_at_all.3 MPI_File_write_at_all_begin.3		\
		MPI_File_write_at_all_end.3 MPI_File_write_ordered.3		\
		MPI_File_write_ordered_begin.3 MPI_File_write_ordered_end.3	\
		MPI_File_write_shared.3 MPI_Finalize.3 MPI_Finalized.3		\
		MPI_Free_mem.3 MPI_Gather.3 MPI_Gatherv.3 MPI_Get.3		\
		MPI_Get_address.3 MPI_Get_count.3 MPI_Get_elements.3		\
		MPI_Get_processor_name.3 MPI_Get_version.3 MPI_Graph_create.3	\
		MPI_Graph_get.3 MPI_Graph_map.3 MPI_Graph_neighbors.3		\
		MPI_Graph_neighbors_count.3 MPI_Graphdims_get.3			\
		MPI_Grequest_complete.3 MPI_Grequest_start.3 MPI_Group_compare.3\
		MPI_Group_difference.3 MPI_Group_excl.3 MPI_Group_free.3	\
		MPI_Group_incl.3 MPI_Group_intersection.3 MPI_Group_range_excl.3\
		MPI_Group_range_incl.3 MPI_Group_rank.3 MPI_Group_size.3	\
		MPI_Group_translate_ranks.3 MPI_Group_union.3 MPI_Ibsend.3	\
		MPI_Info_create.3 MPI_Info_delete.3 MPI_Info_dup.3		\
		MPI_Info_free.3 MPI_Info_get.3 MPI_Info_get_nkeys.3		\
		MPI_Info_get_nthkey.3 MPI_Info_get_valuelen.3 MPI_Info_set.3	\
		MPI_Init.3 MPI_Init_thread.3 MPI_Initialized.3			\
		MPI_Intercomm_create.3 MPI_Intercomm_merge.3 MPI_Iprobe.3	\
		MPI_Irecv.3 MPI_Irsend.3 MPI_Is_thread_main.3 MPI_Isend.3	\
		MPI_Issend.3 MPI_Keyval_create.3 MPI_Keyval_free.3		\
		MPI_Lookup_name.3 MPI_Op_create.3 MPI_Op_free.3 MPI_Open_port.3	\
		MPI_Pack.3 MPI_Pack_external.3 MPI_Pack_external_size.3		\
		MPI_Pack_size.3 MPI_Pcontrol.3 MPI_Probe.3 MPI_Publish_name.3	\
		MPI_Put.3 MPI_Query_thread.3 MPI_Recv.3 MPI_Recv_init.3		\
		MPI_Reduce.3 MPI_Reduce_scatter.3 MPI_Register_datarep.3	\
		MPI_Request_free.3 MPI_Request_get_status.3 MPI_Rsend.3		\
		MPI_Rsend_init.3 MPI_Scan.3 MPI_Scatter.3 MPI_Scatterv.3	\
		MPI_Send.3 MPI_Send_init.3 MPI_Sendrecv.3 MPI_Sendrecv_replace.3\
		MPI_Ssend.3 MPI_Ssend_init.3 MPI_Start.3 MPI_Startall.3		\
		MPI_Status_set_cancelled.3 MPI_Status_set_elements.3 MPI_Test.3	\
		MPI_Test_cancelled.3 MPI_Testall.3 MPI_Testany.3 MPI_Testsome.3	\
		MPI_Topo_test.3 MPI_Type_commit.3 MPI_Type_contiguous.3		\
		MPI_Type_create_darray.3 MPI_Type_create_hindexed.3		\
		MPI_Type_create_hvector.3 MPI_Type_create_indexed_block.3	\
		MPI_Type_create_keyval.3 MPI_Type_create_resized.3		\
		MPI_Type_create_struct.3 MPI_Type_create_subarray.3		\
		MPI_Type_delete_attr.3 MPI_Type_dup.3 MPI_Type_extent.3		\
		MPI_Type_free.3 MPI_Type_free_keyval.3 MPI_Type_get_attr.3	\
		MPI_Type_get_contents.3 MPI_Type_get_envelope.3			\
		MPI_Type_get_extent.3 MPI_Type_get_name.3			\
		MPI_Type_get_true_extent.3 MPI_Type_hindexed.3			\
		MPI_Type_hvector.3 MPI_Type_indexed.3 MPI_Type_lb.3		\
		MPI_Type_match_size.3 MPI_Type_set_attr.3 MPI_Type_set_name.3	\
		MPI_Type_size.3 MPI_Type_struct.3 MPI_Type_ub.3			\
		MPI_Type_vector.3 MPI_Unpack.3 MPI_Unpack_external.3		\
		MPI_Unpublish_name.3 MPI_Wait.3 MPI_Waitall.3 MPI_Waitany.3	\
		MPI_Waitsome.3 MPI_Win_call_errhandler.3 MPI_Win_complete.3	\
		MPI_Win_create.3 MPI_Win_create_errhandler.3			\
		MPI_Win_create_keyval.3 MPI_Win_delete_attr.3 MPI_Win_fence.3	\
		MPI_Win_free.3 MPI_Win_free_keyval.3 MPI_Win_get_attr.3		\
		MPI_Win_get_errhandler.3 MPI_Win_get_group.3 MPI_Win_get_name.3	\
		MPI_Win_lock.3 MPI_Win_post.3 MPI_Win_set_attr.3		\
		MPI_Win_set_errhandler.3 MPI_Win_set_name.3 MPI_Win_start.3	\
		MPI_Win_test.3 MPI_Win_unlock.3 MPI_Win_wait.3 MPI_Wtick.3	\
		MPI_Wtime.3

THREAD2FIX=	configure src/mpid/ch3/channels/ib/configure
LOCALBASE2FIX=	src/mpe2/src/slog2sdk/trace_rlog/configure	\
		src/mpe2/src/slog2sdk/trace_sample/configure
X11BASE2FIX=	src/mpe2/src/graphics/configure

.include <bsd.port.pre.mk>

PREFIX:=	${PREFIX}/${PORTNAME}

pre-configure:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${THREAD2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${LOCALBASE2FIX:S|^|${WRKSRC}/|}
	${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|g' ${X11BASE2FIX:S|^|${WRKSRC}/|}

post-install:
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/bin
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/bin
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.if defined(MAINTAINER_MODE)
regression-test:	install
.if !exists(${HOME}/.mpd.conf)
	@${ECHO_CMD} "MPD_SECRETWORD=change_on_install" > ${HOME}/.mpd.conf
	${CHMOD} go-r ${HOME}/.mpd.conf
	@${ECHO_MSG} "${HOME}/.mpd.conf has been generated - please change the secret word!"
.endif
	${PREFIX}/bin/mpd &
	(cd ${WRKSRC} && \
	PATH=${PATH}:${PREFIX}/bin ${MAKE} testing)
	${PREFIX}/bin/mpdallexit
.endif

.include <bsd.port.post.mk>

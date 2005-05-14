# New ports collection makefile for:	mpich (portable mpi standard imp.)
# Date created:		2 May 1998
# Whom:                 dbader@ece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	mpich
PORTVERSION=	1.2.6
CATEGORIES=	net parallel
MASTER_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/
DIST_SUBDIR=	mpich

PATCH_SITES=	ftp://ftp.mcs.anl.gov/pub/mpi/patch/${PORTVERSION}/
PATCHFILES=	10039 10243 10246

MAINTAINER=	dbader@ece.unm.edu
COMMENT=	Message Passing Interface (MPI) Library

CONFIGURE_ARGS=	-prefix=${PREFIX}/mpich

.if defined(WITHOUT_X11)
WITHOUT_TK=	yes
CONFIGURE_ARGS+=--disable-mpe_graphics
PLIST_SUB+=	X11="@comment "
.else
USE_XLIB=	yes
CONFIGURE_ARGS+=--enable-mpe_graphics
PLIST_SUB+=	X11=""
.endif

.if defined(WITHOUT_TK)
CONFIGURE_ARGS+=-mpe_opts="--without-tcldir --without-tkdir --without-wishloc"
PLIST_SUB+=	TK="@comment "
.else
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
BUILD_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS+=-mpe_opts="--with-wishloc=wish8.4"
PLIST_SUB+=	TK=""
.endif

.if defined(WITHOUT_JAVA) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--without-java
PLIST_SUB+=	JAVA="@comment "
.else
USE_JAVA=	yes
JAVA_VERSION=	1.4+
RUN_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
BUILD_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper
PLIST_SUB+=	JAVA=""
.endif

HAS_CONFIGURE=	yes

ALL_TARGET=

MANPREFIX=	${PREFIX}/mpich

MAN1=		MPI.1 cleanipcs.1 mpiCC.1 mpicc.1 mpif77.1 mpif90.1 mpiman.1		\
		mpireconfig.1 mpirun.1 Jumpshots.1 chp4_servs.1 tstmachines.1
MAN3=		MPI_File_get_position.3 MPI_File_preallocate.3				\
		MPI_2DOUBLE_PRECISION.3 MPI_2INT.3 MPI_2INTEGER.3 MPI_2REAL.3		\
		MPI_ANY_SOURCE.3 MPI_ANY_TAG.3 MPI_Abort.3 MPI_Address.3 MPI_Aint.3	\
		MPI_Allgatherv.3 MPI_Allreduce.3 MPI_Alltoall.3 MPI_Alltoallv.3		\
		MPI_ERR_REQUEST.3 MPIO_Wait.3 MPI_Attr_get.3 MPI_Attr_put.3 MPI_BAND.3	\
		MPI_BOR.3 MPI_BOTTOM.3 MPI_BSEND_OVERHEAD.3 MPI_BXOR.3 MPI_BYTE.3	\
		MPI_Barrier.3 MPI_Bcast.3 MPI_Bsend_init.3 MPI_Buffer_attach.3		\
		MPI_Buffer_detach.3 MPI_CART.3 MPI_CHAR.3 MPI_COMM_SELF.3		\
		MPI_COMM_WORLD.3 MPI_COMPLEX.3 MPI_CONGRUENT.3 MPI_Cancel.3		\
		MPI_Cart_coords.3 MPI_Cart_create.3 MPI_Cart_get.3 MPI_Cart_map.3	\
		MPI_Cart_rank.3 MPI_Cart_shift.3 MPI_Cart_sub.3 MPI_Comm_compare.3	\
		MPI_Comm_create.3 MPI_Comm_dup.3 MPI_Comm_free.3 MPI_Comm_group.3	\
		MPI_Comm_get_name.3 MPI_Comm_rank.3 MPI_Comm_remote_size.3		\
		MPI_Comm_size.3 MPI_Comm_split.3 MPI_Comm_set_name.3			\
		MPI_Comm_test_inter.3 MPI_Copy_function.3 MPI_DATATYPE_NULL.3		\
		MPI_DOUBLE.3 MPI_DOUBLE_COMPLEX.3 MPI_DOUBLE_INT.3			\
		MPI_DOUBLE_PRECISION.3 MPI_DUP_FN.3 MPI_Delete_function.3		\
		MPI_Dims_create.3 MPI_ERROR.3 MPI_ERRORS_ARE_FATAL.3			\
		MPI_ERRORS_RETURN.3 MPI_ERR_ARG.3 MPI_IO.3 MPI_ERR_BUFFER.3		\
		MPI_ERR_BUFFER_EXISTS.3 MPI_ERR_COMM.3 MPI_ERR_COMM_INTER.3		\
		MPI_ERR_COMM_INTRA.3 MPI_ERR_COMM_NULL.3 MPI_ERR_COUNT.3		\
		MPI_ERR_DIMS.3 MPI_ERR_ERRORCODE.3 MPI_ERR_GROUP.3 MPI_ERR_INIT.3	\
		MPI_ERR_INTERN.3 MPI_ERR_IN_STATUS.3 MPI_ERR_LASTCODE.3			\
		MPI_ERR_LIMIT.3 MPI_ERR_NOMATCH.3 MPI_ERR_OP.3 MPI_ERR_NULL.3		\
		MPI_ERR_PERM_KEY.3 MPI_ERR_PERM_OP.3 MPI_ERR_PERM_TYPE.3		\
		MPI_ERR_PRE_INIT.3 MPI_ERR_RANK.3 MPI_ERR_ROOT.3 MPI_ERR_TAG.3		\
		MPI_ERR_TOPOLOGY.3 MPI_ERR_TRUNCATE.3 MPI_ERR_TYPE.3 MPI_ERR_UNKNOWN.3	\
		MPI_Errhandler_free.3 MPI_Errhandler_get.3 MPI_Errhandler_set.3		\
		MPI_FLOAT.3 MPI_GRAPH.3 MPI_Error_class.3 MPI_FLOAT_INT.3		\
		MPI_Finalize.3 MPI_Gather.3 MPI_File_delete.3 MPI_File_f2c.3		\
		MPI_File_get_amode.3 MPI_File_get_atomicity.3				\
		MPI_File_get_byte_offset.3 MPI_File_get_group.3				\
		MPI_File_set_errhandler.3 MPI_File_get_info.3 MPI_File_iread.3		\
		MPI_File_set_size.3 MPI_File_get_size.3 MPI_File_read.3			\
		MPI_File_get_view.3 MPI_File_iread_at.3 MPI_File_iread_shared.3		\
		MPI_File_iwrite.3 MPI_File_iwrite_at.3 MPI_File_iwrite_shared.3		\
		MPI_File_open.3 MPI_File_read_all.3 MPI_File_read_at_all_begin.3	\
		MPI_File_read_all_begin.3 MPI_File_read_all_end.3 MPI_File_read_at.3	\
		MPI_File_read_at_all.3 MPI_File_read_ordered.3 MPI_Info_get_nthkey.3	\
		MPI_File_read_ordered_begin.3 MPI_File_read_ordered_end.3		\
		MPI_File_read_shared.3 MPI_File_seek.3 MPI_File_set_atomicity.3		\
		MPI_File_set_info.3 MPI_File_write.3 MPI_File_sync.3			\
		MPI_File_write_all.3 MPI_File_write_all_begin.3				\
		MPI_File_write_all_end.3 MPI_HOST.3 MPI_File_write_at.3			\
		MPI_File_write_at_all.3 MPI_File_write_at_all_end.3			\
		MPI_Type_create_subarray.3 MPI_File_write_ordered.3			\
		MPI_File_write_ordered_end.3 MPI_File_write_shared.3 MPI_Info_c2f.3	\
		MPI_Info_create.3 MPI_GROUP_EMPTY.3 MPI_GROUP_NULL.3 MPI_Gatherv.3	\
		MPI_Get_count.3 MPI_Get_elements.3 MPI_Get_processor_name.3		\
		MPI_Get_version.3 MPI_Graph_create.3 MPI_Graph_get.3 MPI_Graph_map.3	\
		MPI_Graph_neighbors.3 MPI_Graphdims_get.3 MPI_Group_compare.3		\
		MPI_Group_difference.3 MPI_Group_excl.3 MPI_Group_free.3		\
		MPI_Group_incl.3 MPI_Group_intersection.3 MPI_Group_range_excl.3	\
		MPI_Group_range_incl.3 MPI_Group_rank.3 MPI_Group_size.3		\
		MPI_Group_translate_ranks.3 MPI_Group_union.3 MPI_Handler_function.3	\
		MPI_IDENT.3 MPI_INT.3 MPI_INTEGER.3 MPI_INTEGER1.3 MPI_INTEGER2.3	\
		MPI_INTEGER4.3 MPI_Ibsend.3 MPI_Info_delete.3 MPI_Info_dup.3		\
		MPIO_Request_c2f.3 MPI_Info_f2c.3 MPI_Info_free.3 MPI_LB.3		\
		MPI_Info_get_nkeys.3 MPI_Info_get_valuelen.3 MPI_File_get_errhandler.3	\
		MPI_Info_set.3 MPI_Init.3 MPI_Initialized.3 MPI_Int2handle.3		\
		MPI_Intercomm_create.3 MPI_Intercomm_merge.3 MPI_Iprobe.3 MPI_Irecv.3	\
		MPI_Irsend.3 MPI_Isend.3 MPI_Issend.3 MPI_KEYVAL_INVALID.3		\
		MPI_Keyval_create.3 MPI_Keyval_free.3 MPI_LAND.3 MPI_LOGICAL.3		\
		MPI_LONG.3 MPI_LONG_DOUBLE.3 MPI_LONG_INT.3 MPI_LONG_LONG_INT.3		\
		MPI_LOR.3 MPI_LXOR.3 MPI_MAX.3 MPI_MAXLOC.3 MPI_MAX_ERROR_STRING.3	\
		MPI_MAX_PROCESSOR_NAME.3 MPI_MIN.3 MPI_MINLOC.3 MPI_NULL_COPY_FN.3	\
		MPI_NULL_DELETE_FN.3 MPI_OP_NULL.3 MPI_Op_create.3 MPI_PACKED.3		\
		MPI_PROC_NULL.3 MPI_PROD.3 MPI_Pack.3 MPI_Pack_size.3 MPI_Pcontrol.3	\
		MPI_Probe.3 MPI_REAL.3 MPI_REAL8.3 MPI_REQUEST_NULL.3 MPI_Recv.3	\
		MPI_Recv_init.3 MPI_Reduce.3 MPI_Rsend.3 MPI_Request_c2f.3		\
		MPI_Rsend_init.3 MPI_SHORT.3 MPI_SHORT_INT.3 MPI_SIMILAR.3		\
		MPI_SOURCE.3 MPI_SUCCESS.3 MPI_SUM.3 MPI_Scan.3 MPI_Scatter.3		\
		MPI_Scatterv.3 MPI_Send.3 MPI_Send_init.3 MPI_Sendrecv.3		\
		MPI_Sendrecv_replace.3 MPI_Ssend.3 MPI_Ssend_init.3 MPI_Start.3		\
		MPI_Status_c2f.3 MPI_Status_set_cancelled.3 MPI_Status_set_elements.3	\
		MPI_TAG.3 MPI_TAG_UB.3 MPI_Test.3 MPI_Test_cancelled.3 MPI_Testall.3	\
		MPI_Testany.3 MPI_Testsome.3 MPI_Topo_test.3 MPI_Type_contiguous.3	\
		MPI_Type_create_indexed_block.3 MPI_Init_thread.3 MPI_UB.3		\
		MPI_Unpack.3 MPI_Type_free.3 MPI_Type_get_envelope.3			\
		MPI_Type_hindexed.3 MPI_Type_hvector.3 MPI_Type_lb.3 MPI_Type_size.3	\
		MPI_Type_struct.3 MPI_Type_ub.3 MPI_Type_vector.3 MPI_UNDEFINED.3	\
		MPI_UNDEFINED_RANK.3 MPI_UNEQUAL.3 MPI_UNSIGNED.3 MPI_UNSIGNED_CHAR.3	\
		MPI_UNSIGNED_LONG.3 MPI_UNSIGNED_SHORT.3 MPI_User_function.3		\
		MPI_WTIME_IS_GLOBAL.3 MPI_Wait.3 MPI_Waitall.3 MPI_Waitany.3		\
		MPI_Waitsome.3 MPI_Wtick.3 MPI_Wtime.3 MPIO_Test.3 Constants.3		\
		MPI_2COMPLEX.3 MPI_2DOUBLE_COMPLEX.3 MPI_Allgather.3 MPI_Attr_delete.3	\
		MPI_Bsend.3 MPI_COMM_NULL.3 MPI_Cartdim_get.3 MPI_Comm_remote_group.3	\
		MPI_ERRHANDLER_NULL.3 MPI_ERR_BAD_ARGS.3 MPI_ERR_EXHAUSTED.3		\
		MPI_ERR_OTHER.3 MPI_Errhandler_create.3 MPI_Error_string.3		\
		MPI_Finalized.3 MPI_Graph_neighbors_count.3 MPI_Info_get.3		\
		MPI_Type_create_darray.3 MPI_LONG_DOUBLE_INT.3 MPI_Op_free.3		\
		MPI_REAL4.3 MPI_Reduce_scatter.3 MPI_Request_free.3 MPI_Startall.3	\
		MPI_Type_commit.3 MPI_Type_extent.3 MPI_Type_get_contents.3		\
		MPI_Type_indexed.3 MPI_File_c2f.3 MPI_File_close.3			\
		MPI_File_get_position_shared.3 MPI_File_get_type_extent.3		\
		MPI_File_read_at_all_end.3 MPI_File_seek_shared.3 MPI_File_set_view.3	\
		MPI_File_write_ordered_begin.3 MPIO_Request_f2c.3			\
		MPI_File_write_at_all_begin.3
MAN4=		CLOG_Init.4 CLOG_commtype.4 CLOG_cput.4 CLOG_csync.4			\
		CLOG_get_new_event.4 CLOG_get_new_state.4 CLOG_init_buffers.4		\
		CLOG_mergelogs.4 CLOG_mergend.4 CLOG_msgtype.4 CLOG_procbuf.4 MPE.4	\
		CLOG_newbuff.4 CLOG_reclen.4 CLOG_reinit_buff.4 CLOG_treesetup.4	\
		MPE_Add_RGB_color.4 MPE_CaptureFile.4 MPE_Close_graphics.4		\
		MPE_Comm_global_rank.4 MPE_Counter_create.4 MPE_Counter_free.4		\
		MPE_Counter_nxtval.4 MPE_Decomp1d.4 MPE_Describe_state.4		\
		MPE_Draw_circle.4 MPE_Draw_line.4 MPE_Draw_logic.4 MPE_Draw_point.4	\
		MPE_Draw_points.4 MPE_Draw_string.4 MPE_Fill_circle.4			\
		MPE_Fill_rectangle.4 MPE_Finish_log.4 MPE_GetTags.4			\
		MPE_IO_Stdout_to_file.4 MPE_Iget_mouse_press.4 MPE_Init_log.4		\
		MPE_Initialized_logging.4 MPE_Line_thickness.4 MPE_Log_event.4		\
		MPE_Log_get_event_number.4 MPE_Log_receive.4 MPE_Log_send.4		\
		MPE_Num_colors.4 MPE_Open_graphics.4 MPE_Print_datatype_pack_action.4	\
		MPE_Seq_begin.4 MPE_Update.4 MPE_ReturnTags.4 MPE_Seq_end.4		\
		MPE_Start_log.4 MPE_Stop_log.4 MPE_TagsEnd.4 CLOG_Finalize.4		\
		CLOG_Output.4 CLOG_nodebuffer2disk.4 CLOG_rectype.4			\
		MPE_Describe_event.4 MPE_Get_mouse_press.4 MPE_Make_color_array.4	\
		MPE_Print_datatype_unpack_action.4

.include <bsd.port.pre.mk>

# To disable ssh client support, build with WITHOUT_SSH set.
# Use ssh instead of rsh
.if !defined(WITHOUT_SSH)
.if ${OSVERSION} >= 400016 && exists(/usr/bin/ssh)
CONFIGURE_ENV+=	RSHCOMMAND="/usr/bin/ssh"
.elif defined(WITH_SSH) || exists(${LOCALBASE}/bin/ssh)
RUN_DEPENDS+=	${LOCALBASE}/bin/ssh:${PORTSDIR}/security/ssh
CONFIGURE_ENV+=	RSHCOMMAND="${LOCALBASE}/bin/ssh"
.endif
.endif

post-install:
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/mpich/bin ${PREFIX}/mpich/lib
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/mpich/doc ${PREFIX}/mpich/include	\
		${PREFIX}/mpich/share
.if ! defined(WITHOUT_JAVA) && ! defined(PACKAGE_BUILDING)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/mpich/logfiles
.endif

.if defined(MAINTAINER_MODE)
test:	build
	(cd ${WRKSRC}/examples/test ;	\
	${MAKE} testing)
.endif

.include <bsd.port.post.mk>

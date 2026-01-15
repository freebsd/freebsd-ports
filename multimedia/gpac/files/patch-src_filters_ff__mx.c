--- src/filters/ff_mx.c.orig	2024-04-17 17:18:21 UTC
+++ src/filters/ff_mx.c
@@ -1330,7 +1330,14 @@ static GF_Err ffmx_configure_pid(GF_Filter *filter, GF
 		u8 *data = av_malloc(sizeof(u32) * 9);
 		if (data) {
 			memcpy(data, p->value.uint_list.vals, sizeof(u32)*9);
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 			av_stream_add_side_data(st->stream, AV_PKT_DATA_DISPLAYMATRIX, data, 32*9);
+#else
+			av_packet_side_data_add(&st->stream->codecpar->coded_side_data,
+									&st->stream->codecpar->nb_coded_side_data,
+									AV_PKT_DATA_DISPLAYMATRIX,
+									data, 32 * 9, 0);
+#endif
 		}
 	}
 #if (LIBAVCODEC_VERSION_MAJOR>58)
@@ -1340,7 +1347,14 @@ static GF_Err ffmx_configure_pid(GF_Filter *filter, GF
 		u8 *data = av_malloc(p->value.data.size);
 		if (data) {
 			memcpy(data, p->value.data.ptr, p->value.data.size);
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 			av_stream_add_side_data(st->stream, AV_PKT_DATA_ICC_PROFILE, data, p->value.data.size);
+#else
+			av_packet_side_data_add(&st->stream->codecpar->coded_side_data,
+									&st->stream->codecpar->nb_coded_side_data,
+									AV_PKT_DATA_ICC_PROFILE,
+									data, p->value.data.size, 0);
+#endif
 		}
 	}
 	//clli
@@ -1351,7 +1365,14 @@ static GF_Err ffmx_configure_pid(GF_Filter *filter, GF
 		if (data) {
 			data->MaxCLL = gf_bs_read_u16(bs);
 			data->MaxFALL = gf_bs_read_u16(bs);
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 			av_stream_add_side_data(st->stream, AV_PKT_DATA_CONTENT_LIGHT_LEVEL, (u8*) data, sizeof(AVContentLightMetadata));
+#else
+			av_packet_side_data_add(&st->stream->codecpar->coded_side_data,
+									&st->stream->codecpar->nb_coded_side_data,
+									AV_PKT_DATA_CONTENT_LIGHT_LEVEL,
+									(u8*) data, sizeof(AVContentLightMetadata), 0);
+#endif
 		}
 		gf_bs_del(bs);
 	}
@@ -1385,7 +1406,14 @@ static GF_Err ffmx_configure_pid(GF_Filter *filter, GF
 			data->max_luminance.den = luma_den;
 			data->min_luminance.num = gf_bs_read_u32(bs);
 			data->min_luminance.den = luma_den;
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 			av_stream_add_side_data(st->stream, AV_PKT_DATA_MASTERING_DISPLAY_METADATA, (u8*) data, sizeof(AVMasteringDisplayMetadata));
+#else
+			av_packet_side_data_add(&st->stream->codecpar->coded_side_data,
+				&st->stream->codecpar->nb_coded_side_data,
+				AV_PKT_DATA_MASTERING_DISPLAY_METADATA,
+				(u8*) data, sizeof(AVMasteringDisplayMetadata), 0);
+#endif
     	}
     	gf_bs_del(bs);
 	}
@@ -1403,7 +1431,14 @@ static GF_Err ffmx_configure_pid(GF_Filter *filter, GF
 			data->el_present_flag = gf_bs_read_int(bs, 1);
 			data->bl_present_flag = gf_bs_read_int(bs, 1);
 			data->dv_bl_signal_compatibility_id = gf_bs_read_int(bs, 4);
+#if (LIBAVFORMAT_VERSION_MAJOR < 62)
 			av_stream_add_side_data(st->stream, AV_PKT_DATA_DOVI_CONF, (u8*) data, sizeof(Ref_FFAVDoviRecord));
+#else
+			av_packet_side_data_add(&st->stream->codecpar->coded_side_data,
+									&st->stream->codecpar->nb_coded_side_data,
+									AV_PKT_DATA_DOVI_CONF,
+									(u8*) data, sizeof(Ref_FFAVDoviRecord), 0);
+#endif
 		}
 		gf_bs_del(bs);
 	}

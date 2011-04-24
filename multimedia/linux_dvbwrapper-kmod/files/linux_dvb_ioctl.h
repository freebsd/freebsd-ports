/*-
 * Copyright (c) 2011 Juergen Lock
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer 
 *    in this position and unchanged.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $FreeBSD: /tmp/pcvs/ports/multimedia/linux_dvbwrapper-kmod/files/linux_dvb_ioctl.h,v 1.1 2011-04-24 15:51:13 nox Exp $
 */

#ifndef _LINUX_DVB_IOCTL_H_
#define	_LINUX_DVB_IOCTL_H_

/*
 * ioctl
 *
 * XXX comments in Linux' <asm-generic/ioctl.h> indicate these
 * could be arch-dependant...
 */
#define LINUX_IOC_VOID		0
#define LINUX_IOC_IN		0x40000000
#define LINUX_IOC_OUT		0x80000000
#define LINUX_IOC_INOUT		(LINUX_IOC_IN|LINUX_IOC_OUT)

/*
 * DVB (osd.h and video.h not handled)
 */
#define LINUX_AUDIO_STOP			0x6f01 /* 0x00006f01 */
#define LINUX_AUDIO_PLAY			0x6f02 /* 0x00006f02 */
#define LINUX_AUDIO_PAUSE			0x6f03 /* 0x00006f03 */
#define LINUX_AUDIO_CONTINUE			0x6f04 /* 0x00006f04 */
#define LINUX_AUDIO_SELECT_SOURCE		0x6f05 /* 0x00006f05 */
#define LINUX_AUDIO_SET_MUTE			0x6f06 /* 0x00006f06 */
#define LINUX_AUDIO_SET_AV_SYNC			0x6f07 /* 0x00006f07 */
#define LINUX_AUDIO_SET_BYPASS_MODE		0x6f08 /* 0x00006f08 */
#define LINUX_AUDIO_CHANNEL_SELECT		0x6f09 /* 0x00006f09 */
#define LINUX_AUDIO_GET_STATUS			0x6f0a /* 0x80206f0a */
#define LINUX_AUDIO_GET_CAPABILITIES		0x6f0b /* 0x80046f0b */
#define LINUX_AUDIO_CLEAR_BUFFER		0x6f0c /* 0x00006f0c */
#define LINUX_AUDIO_SET_ID			0x6f0d /* 0x00006f0d */
#define LINUX_AUDIO_SET_MIXER			0x6f0e /* 0x40086f0e */
#define LINUX_AUDIO_SET_STREAMTYPE		0x6f0f /* 0x00006f0f */
#define LINUX_AUDIO_SET_EXT_ID			0x6f10 /* 0x00006f10 */
#define LINUX_AUDIO_SET_ATTRIBUTES		0x6f11 /* 0x40026f11 */
#define LINUX_AUDIO_SET_KARAOKE			0x6f12 /* 0x400c6f12 */
#define LINUX_AUDIO_GET_PTS			0x6f13 /* 0x80086f13 */
#define LINUX_AUDIO_BILINGUAL_CHANNEL_SELECT	0x6f14 /* 0x00006f14 */
#define LINUX_DMX_START				0x6f29 /* 0x00006f29 */
#define LINUX_DMX_STOP				0x6f2a /* 0x00006f2a */
#define LINUX_DMX_SET_FILTER			0x6f2b /* 0x403c6f2b */
#define LINUX_DMX_SET_PES_FILTER		0x6f2c /* 0x40146f2c */
#define LINUX_DMX_SET_BUFFER_SIZE		0x6f2d /* 0x00006f2d */
#define LINUX_DMX_GET_PES_PIDS			0x6f2f /* 0x800a6f2f */
#define LINUX_DMX_GET_CAPS			0x6f30 /* 0x80086f30 */
#define LINUX_DMX_SET_SOURCE			0x6f31 /* 0x40046f31 */
#define LINUX_DMX_GET_STC			0x6f32 /* 0xc0106f32 */
#define LINUX_DMX_ADD_PID			0x6f33 /* 0x40026f33 */
#define LINUX_DMX_REMOVE_PID			0x6f34 /* 0x40026f34 */
#define LINUX_FE_GET_INFO			0x6f3d /* 0x80a86f3d */
#define LINUX_FE_DISEQC_RESET_OVERLOAD		0x6f3e /* 0x00006f3e */
#define LINUX_FE_DISEQC_SEND_MASTER_CMD		0x6f3f /* 0x40076f3f */
#define LINUX_FE_DISEQC_RECV_SLAVE_REPLY	0x6f40 /* 0x800c6f40 */
#define LINUX_FE_DISEQC_SEND_BURST		0x6f41 /* 0x00006f41 */
#define LINUX_FE_SET_TONE			0x6f42 /* 0x00006f42 */
#define LINUX_FE_SET_VOLTAGE			0x6f43 /* 0x00006f43 */
#define LINUX_FE_ENABLE_HIGH_LNB_VOLTAGE	0x6f44 /* 0x00006f44 */
#define LINUX_FE_READ_STATUS			0x6f45 /* 0x80046f45 */
#define LINUX_FE_READ_BER			0x6f46 /* 0x80046f46 */
#define LINUX_FE_READ_SIGNAL_STRENGTH		0x6f47 /* 0x80026f47 */
#define LINUX_FE_READ_SNR			0x6f48 /* 0x80026f48 */
#define LINUX_FE_READ_UNCORRECTED_BLOCKS	0x6f49 /* 0x80046f49 */
#define LINUX_FE_SET_FRONTEND			0x6f4c /* 0x40246f4c */
#define LINUX_FE_GET_FRONTEND			0x6f4d /* 0x80246f4d */
#define LINUX_FE_GET_EVENT			0x6f4e /* 0x80286f4e */
#define LINUX_FE_DISHNETWORK_SEND_LEGACY_CMD	0x6f50 /* 0x00006f50 */
#define LINUX_FE_SET_FRONTEND_TUNE_MODE		0x6f51 /* 0x00006f51 */
#define LINUX_FE_SET_PROPERTY			0x6f52 /* 0x40086f52 */
#define LINUX_FE_GET_PROPERTY			0x6f53 /* 0x80086f53 */
#define LINUX_CA_RESET				0x6f80 /* 0x00006f80 */
#define LINUX_CA_GET_CAP			0x6f81 /* 0x80106f81 */
#define LINUX_CA_GET_SLOT_INFO			0x6f82 /* 0x800c6f82 */
#define LINUX_CA_GET_DESCR_INFO			0x6f83 /* 0x80086f83 */
#define LINUX_CA_GET_MSG			0x6f84 /* 0x810c6f84 */
#define LINUX_CA_SEND_MSG			0x6f85 /* 0x410c6f85 */
#define LINUX_CA_SET_DESCR			0x6f86 /* 0x40106f86 */
#define LINUX_CA_SET_PID			0x6f87 /* 0x40086f87 */

/*
 * DVB net.h
 * (LINUX_NET_ADD_IF and LINUX___NET_ADD_IF_OLD overlap with
 *  LINUX_DMX_REMOVE_PID)
 */
#define LINUX_NET_ADD_IF			0x6f34 /* 0xc0066f34 */
#define LINUX_NET_REMOVE_IF			0x6f35 /* 0x00006f35 */
#define LINUX_NET_GET_IF			0x6f36 /* 0xc0066f36 */
#define LINUX___NET_ADD_IF_OLD			0x6f34 /* 0xc0046f34 */
#define LINUX___NET_GET_IF_OLD			0x6f36 /* 0xc0046f36 */

#define LINUX_IOCTL_DVB_MIN	LINUX_AUDIO_STOP
#define LINUX_IOCTL_DVB_MAX	LINUX_CA_SET_PID

#endif /* !_LINUX_DVB_IOCTL_H_ */

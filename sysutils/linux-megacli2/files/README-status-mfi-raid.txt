# $FreeBSD$

The output of periodic/daily/407.status-mfi-raid uses several
abbreviations. This document maps the abbreviations to the
names MegaCli uses, which were just too long for summary mails.

Section 'Physical Drive Information:'
--------------------------------------------------
ENC	Enclosure Number
SLO	Slot Number
DEV	Device Id
SEQ	Sequence Number
MEC	Media Error Count
OEC	Other Error Count
PFC	Predictive Failure Count
LPF	Last Predictive Failure Event Seq Number
STATE	Firmware state

Section 'Virtual Drive Information:'
--------------------------------------------------
VD	Virtual Disk
DRV	Number Of Drives
RLP	RAID Level: Primary
RLS	RAID Level: Secondary
RLQ	RAID Level: RAID Level Qualifier
STS	Stripe Size
SIZE	Size
STATE	State
NAME	Name

Section 'BBU Information:'
--------------------------------------------------
TYPE	BatteryType
TEMP	Temperature
OK	isSOHGood
RSOC	Relative State of Charge
ASOC	Absolute State of charge
RC	Remaining Capacity
CC	Cycle Count
ME	Max Error

# end

/** dspam 3.1.0 to 3.2.0 mysql migration script */
/** set  myisam_sort_buffer_size to a high value to make this faster */

ALTER TABLE dspam_signature_data DROP COLUMN snr;
CREATE INDEX id_signature_data_02 ON dspam_signature_data(created_on);
DROP TABLE dspam_snr_data;
